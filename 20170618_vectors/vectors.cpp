#include <vector>
#include <iostream>

int main()
{
  std::vector<int> fooVecInt;
  std::vector<float> fooVecFloat;

  fooVecInt.push_back(6);
  fooVecInt.push_back(1023);
  fooVecFloat.push_back(60000);
  fooVecInt.push_back(1023000);

  for (std::vector<int>::size_type idx = 0U; idx < fooVecInt.size(); idx++) {
    std::cout << "&fooVecInt["<< idx <<"]";
    std::cout << '\t' << std::hex << &fooVecInt[idx] << std::endl;
    std::cout << "&fooVecFloat["<< idx <<"]";
    std::cout << '\t' << std::hex << &fooVecFloat[idx] << std::endl;
  }

  return 0;
}
