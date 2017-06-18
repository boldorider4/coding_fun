#include <vector>
#include <iostream>
#include <algorithm>

int main() {
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */
  int N;
  std::vector<int> fooInt;
  
  std::cin >> N;
  for (int idx = 0; idx < N; idx++) {
    int stdin_temp;

    std::cin >> stdin_temp;
    if(!std::cin.fail()) {
      fooInt.push_back(stdin_temp);
    } else {
      return -1;
    }
  }

  std::sort(fooInt.begin(), fooInt.end());
  
  for (auto it = fooInt.begin(); it < fooInt.end(); it++) {
    std::cout << *it << " ";
  }
  
  std::cout << std::endl;
         
  return 0;
}
