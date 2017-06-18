#include <iostream>
#include <set>

int main() {

  std::set<int> setInt;
  unsigned int Q, query;
  int x;

  std::cin >> Q;

  for (unsigned int idx = 0U; idx < Q; idx++) {
    std::cin >> query;
    std::cin >> x;
    
    switch(query) {
    case 1:
      setInt.insert(x);
      break;
    case 2:
      setInt.erase(x);
      break;
    case 3: {
      std::set<int>::iterator it = setInt.find(x);
      if (it == setInt.end()) {
        std::cout << "No" << std::endl;
      } else {
        std::cout << "Yes" << std::endl;
      }
      break;
    }
    default:
      std::cout << "invalid query type" << std::endl;
      return -1;
    }
  }

  return 0;
}
