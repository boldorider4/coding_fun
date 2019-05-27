class fooInterface {
public:
  virtual ~fooInterface() = default;
  
  virtual void fooFunc0() = 0;
  virtual void fooFunc1() = 0;
};

class FooChildFirst : public fooInterface {
public:
  FooChildFirst() = default;
  virtual ~FooChildFirst() = default;
  
  virtual void fooFunc0() {}
  virtual void fooFunc1() {}
};


class FooChildSecond : public fooInterface {
public:
  FooChildSecond() = default;
  virtual ~FooChildSecond() = default;
  
  virtual void fooFunc0() {}
  virtual void fooFunc1() {}
};


int main() {
  fooInterface* interface = new FooChildFirst();
  interface->fooFunc0();
  interface->fooFunc1();

  delete interface;

  return 0;
}
