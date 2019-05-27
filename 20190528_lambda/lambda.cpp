#include <array>
#include <algorithm>
#include <iostream>


int assertContainsMultipleOfTwo(const auto& array) {
  int error = 0;
  
  auto lambdaFunc = [&error](const auto& arrayEl) -> void {
    if (!(arrayEl % 2)) {
      std::cout << "element " << arrayEl << " is a multiple of 2" << std::endl;
    } else {
      std::cerr << "element " << arrayEl << " is NOT a multiple of 2. Quitting..." << std::endl;
      error = -1;
      return;
    }
  };

  std::for_each(array.begin(), array.end(), lambdaFunc);
  return error;
}


int main() {

  std::array<int, 5> fooArray = {8,6,4,4,3};
  return assertContainsMultipleOfTwo(fooArray);
}
