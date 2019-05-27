#include <memory>
#include <iostream>


class fooClass {
 public:
  fooClass() = default;
  ~fooClass() {
    std::cout << "called custom destructor" << std::endl;
  }
  void dostuff() {
    std::cout << "do stuff" << std::endl;
  }
};


fooClass* getInstance() {
  return new fooClass();
};


int main() {
  std::unique_ptr<fooClass> fclass = std::unique_ptr<fooClass>(getInstance());
  fclass->dostuff();
  return 0;
}
