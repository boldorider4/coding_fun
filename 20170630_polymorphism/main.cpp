#include <iostream>

class A {
public:
  virtual void foo() { std::cout << "A foo was called" << std::endl; }
};

class B : public A {
public:
  virtual void foo() { std::cout << "B foo was called" << std::endl; }
};

class C : public B {
public:
  virtual void foo() { std::cout << "C foo was called" << std::endl; }
};

class D : public C {
public:
  virtual void foo() { std::cout << "D foo was called" << std::endl; }
};


int main() {

  C fooC;
  A* pfooC = &fooC;

  fooC.foo();
  pfooC->foo();
  dynamic_cast<B*>(pfooC)->foo();
  D* pfooC_D = dynamic_cast<D*>(pfooC);
  if (pfooC_D != nullptr)
    pfooC_D->foo();
  static_cast<B>(fooC).foo();

  return 0;
}
