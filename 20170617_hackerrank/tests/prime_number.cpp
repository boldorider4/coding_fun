#include <iostream>
#include <cmath>

using namespace std;


int main() {
  for (int prime = 2; prime < 1000; prime++) {
    for (int factor = 2; factor*factor <= prime; factor++)
      {
        if (prime % factor == 0) {
          break;
        } else if ((factor+1)*(factor+1) > prime) {
          cout << prime << " ";
        }
      }
  }
  
  cout << endl;
  
  return 0;
}
