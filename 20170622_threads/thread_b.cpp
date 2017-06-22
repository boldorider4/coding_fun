#include <iostream>
#include <mutex>
#include <thread>
#include <cmath>
#include <functional>

using namespace std::chrono;

class Record {

public:
  std::mutex mtx;
  Record(int Data) : data(Data) {}
  int getData() { return data; }
  int& getDataHandle() { return static_cast<int&>(data); }

private:
  int data;
};

class thread_a {
public:
  thread_a(Record* res_i) : res(res_i) {}

  void operator()() {
    std::this_thread::sleep_for(milliseconds(19));
    std::unique_lock<std::mutex> lockThrdA(res->mtx);
    
    int& data = res->getDataHandle();
    data = static_cast<int>(std::pow(data, 3));
    std::cout << "thread a " << data << std::endl;
    
    lockThrdA.unlock();
  }

private:
  Record* res;
};

class thread_b {
public:
  thread_b(Record* res_i) : res(res_i) {}

  void operator()() {
    std::this_thread::sleep_for(milliseconds(19));
    std::unique_lock<std::mutex> lockThrdA(res->mtx);
    
    int& data = res->getDataHandle();
    data = static_cast<int>(std::sqrt(static_cast<float>(data)));
    std::cout << "thread b " << data << std::endl;
    
    lockThrdA.unlock();
  }

private:
  Record* res;
};

int main() {

  Record a(25);
  std::cout << "before thread a and b " << a.getData() << std::endl;

  thread_a thread_a_func(&a);
  thread_b thread_b_func(&a);

  std::thread ta (thread_a_func);
  std::thread tb (thread_b_func);

  ta.join();
  tb.join();

  std::cout << "after thread a and b " << a.getData() << std::endl;

  return 0;
}
