#include <cmath>
#include <vector>
#include <iostream>
#include <iterator>

int main()
{
  std::vector<int> vecInt;
  unsigned int N;
  unsigned int uTemp1, uTemp2;
  int temp;
  std::vector<int>::iterator it1, it2;
  
  std::cin >> N;
  if (!std::cin.fail()) {
    for (unsigned int idx = 0; idx < N; idx++) {
      std::cin >> temp;
      if (!std::cin.fail()) {
        vecInt.push_back(temp);
      } else {
        return -1;
      }
    }
  } else {
    return -1;
  }

  std::cin >> uTemp1;
  if (std::cin.fail() || !uTemp1) {
    return -1;
  }

  it1 = vecInt.begin() + uTemp1 - 1;
  vecInt.erase(it1);

  std::cin >> uTemp1;
  if (std::cin.fail() || !uTemp1) {
    return -1;
  }
  std::cin >> uTemp2;
  if (std::cin.fail() || !uTemp2) {
    return -1;
  }

  it1 = vecInt.begin() + uTemp1 - 1;
  it2 = vecInt.begin() + uTemp2 - 1;
  vecInt.erase(it1, it2);

  std::cout << vecInt.size() << std::endl;
  for (auto& it : vecInt) {
    std::cout << it << " ";
  }
  std::cout << std::endl;
  
  return 0;
}
