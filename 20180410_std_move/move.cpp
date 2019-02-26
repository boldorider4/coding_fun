#include <iostream>


class FooClass {
 public:
  FooClass() = default;
  ~FooClass() = default;
  FooClass(FooClass&) { std::cout << "FooClass copy constructor called" << std::endl; };
  FooClass(FooClass&&) { std::cout << "FooClass move constructor called" << std::endl; };
};

class FooClassMoveDeleted {
 public:
  FooClassMoveDeleted() = default;
  ~FooClassMoveDeleted() = default;
  FooClassMoveDeleted(FooClassMoveDeleted&) { std::cout << "FooClassMoveDeleted copy constructor called" << std::endl; };
  FooClassMoveDeleted(FooClassMoveDeleted&&) = delete;
};


int main() {

  FooClass a;
  auto b = std::move(a);
  const auto c = std::move(b);

  FooClassMoveDeleted d;
  // auto e = std::move(d);
  // const auto f = std::move(e);
  
  return 0;
}
