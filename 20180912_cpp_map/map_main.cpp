#include <vector>
#include <map>
#include <iostream>

int main() {

  std::vector<int> vectorOfNumbers = {34, 1, 1000, 344, 23, 35};
  std::map<int, int> numberMap;

  for (auto number : vectorOfNumbers) {
    numberMap.insert(std::pair<int, int>{number, number});
  }

  std::cout << "numberMap contains (in order):" << std::endl;

  for (auto pair : numberMap) {
    std::cout << pair.second << std::endl;
  }

  int size = numberMap.size();
  std::cout << "the size of the map is " << size << std::endl;
  std::cout << "the value of the median is ";

  int count = 0;
  float number = 0;

  if (size % 2) {
    for (auto number_it = numberMap.begin(); count <= size/2; number_it++, count++) {
      number = number_it->first;
    }
    std::cout << number << std::endl;
  } else {
    for (auto number_it = numberMap.begin(); count <= size/2; number_it++, count++) {
      if (count == size/2 - 1 || count == size/2) {
	number += number_it->first;
      }
    }
    std::cout << number/2 << std::endl;
  }

  return 0;
}
