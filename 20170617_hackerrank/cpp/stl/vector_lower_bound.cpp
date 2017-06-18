#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
  std::vector<int> vecInt, queries;
  unsigned int N;
  int temp;
  std::vector<int>::iterator it;

  std::cin >> N;
  if (std::cin.fail()) return -1;

  for (unsigned int idx = 0; idx < N; idx++) {
    std::cin >> temp;
    if (std::cin.fail()) return -1;
    vecInt.push_back(temp);
  }

  std::cin >> N;
  if (std::cin.fail()) return -1;

  for (unsigned int idx = 0; idx < N; idx++) {
    std::cin >> temp;
    if (std::cin.fail()) return -1;
    queries.push_back(temp);
  }

  for (auto& queries_it : queries) {
    it = std::lower_bound(vecInt.begin(), vecInt.end(), queries_it);
    N = (unsigned int)std::distance(vecInt.begin(), it) + 1;
    if (*it == queries_it) {
      std::cout << "Yes ";
    } else {
      std::cout << "No ";
    }
    std::cout << N << std::endl;
  }

  return 0;
}
