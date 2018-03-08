#include <iostream>


class ObjectA {

  friend std::ostream& operator<<(std::ostream& os, const ObjectA& obj);

public:
  ObjectA();
  ObjectA(const ObjectA& obj);
  ObjectA(ObjectA&& obj);
  ~ObjectA() = default;
  ObjectA& operator=(const ObjectA& obj);
  void twistObject();

private:
  int* array{nullptr};
  bool initialized{false};
};


ObjectA::ObjectA() {

  array = new int[10];

  for (unsigned int ix = 0; ix < 10; ix++) {
    array[ix] = ix;
  }

  initialized = true;
}


ObjectA::ObjectA(const ObjectA& obj) {

  std::cout << "copy constructor called" << std::endl;

  /* we don't need to check whether obj and this are the same */
  array = new int[10];

  for (unsigned int ix = 0; ix < 10; ix++) {
    array[ix] = obj.array[ix];
  }

  initialized = true;
}


ObjectA::ObjectA(ObjectA&& obj) {

  std::cout << "move constructor called" << std::endl;

  /* we don't need to check whether obj and this are the same */
  std::swap(array, obj.array);
  std::swap(initialized, obj.initialized);
}


ObjectA& ObjectA::operator=(const ObjectA& obj) {

  std::cout << "copy assignment called" << std::endl;

  if (this != &obj) {
    array = obj.array;
    array[3] = 2000;
    initialized = true;
  }

  return *this;
}

void ObjectA::twistObject() {
  if (initialized) {
    array[5] = 1000;
  }
}


std::ostream& operator<<(std::ostream& os, const ObjectA& obj) {

  for (unsigned int ix = 0; ix < 10; ix++) {
    os << obj.array[ix] << "; ";
  }

  os << std::endl;

  return os;
}

int main() {

  ObjectA a;
  std::cout << "a: " << a;

  ObjectA b = a;
  b = a;
  b = std::move(b);
  a.twistObject();
  std::cout << "b after twist on a: " << b;
  std::cout << "a after twist on a: " << a;

  ObjectA c = ObjectA();

  return 0;
}
