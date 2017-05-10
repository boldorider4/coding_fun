#include <iostream>

class learningClass
{
public:

  learningClass(int& x);
  long long getMemberAddress();

private:

  int& aMember;
};

learningClass::learningClass(int& x): aMember(x)
{
}

long long learningClass::getMemberAddress()
{
  return (long long)&aMember;
}

int main()
{
  int var = 0;
  long long var_addr;
  learningClass lC(var);

  var_addr = (long long)&var;
  std::cout << "0x" << std::hex << var_addr << std::endl;
  var_addr = lC.getMemberAddress();
  std::cout << "0x" << std::hex << var_addr << std::endl;
  std::cout << "everything ok!" << std::endl;
  return 0;
}
