#include <memory>
#include <iostream>

struct Foo
{
  Foo() { std::cout << "Foo ...\n"; }
  ~Foo() { std::cout << "~Foo ...\n"; }
  std::string text = "Hi World!";
};

std::weak_ptr<Foo> gWeak;

void observe()
{
  std::cout << "use_count:" << gWeak.use_count() << ": ";

  if (auto tempShared = gWeak.lock())
    {
      std::cout << tempShared->text << "\n";
    }
  else
    {
      std::cout << "gWeak is expired\n";
    }
}

int main()
{
  {
    std::shared_ptr<Foo> shared =  std::make_shared<Foo>();
    gWeak = shared;
    observe();
  }

  observe();
  return 0;
}
