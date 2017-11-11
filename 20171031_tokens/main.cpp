#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> tokens) {
  int n = tokens.size();
  int result = 0;
  for (int idx = 0; idx < n-1; idx++) {
    if (tokens[idx] == tokens[idx+1]) {
      result++;
    }
  }

  /* r should start from the worst case scenario where 
     all digits are the same, so the bug was r = 0 instead
     r = -1 */
  int r = -1;

  for (int idx = 0; idx < n; idx++) {

    int count = 0;
    if (idx > 0) {
      if (tokens[idx] != tokens[idx-1]) {
        count += 1;
      } else {
        count -= 1;
      }
    }

    if (idx < n-1) {
      if (tokens[idx] != tokens[idx+1]) {
        count += 1;
      } else {
        count -= 1;
      }
    }

    r = max(r, count);
  }

  return result + r;
}

int main() {

  vector<int> test1{1,1,1,0,0,1,0,1,0,1,1,0,0};
  cout << "test1 = {1,1,1,0,0,1,0,1,0,1,1,0,0};" << endl;
  cout << "solution(test1) = " << solution(test1) << "\n" << endl;

  vector<int> test2{1,1,1,0,0,0,0,0,0,1,1,0,0};
  cout << "test2 = {1,1,1,0,0,0,0,0,0,1,1,0,0};" << "\n" << endl;
  cout << "solution(test2) = " << solution(test2) << "\n" << endl;

  vector<int> test3{1,0,1,0,1,0,1,0,1};
  cout << "test3 = {1,0,1,0,1,0,1,0,1};" << "\n" << endl;
  cout << "solution(test3) = " << solution(test3) << "\n" << endl;

  vector<int> test4{0,0,0,0,0};
  cout << "test4 = {0,0,0,0,0};" << "\n" << endl;
  cout << "solution(test4) = " << solution(test4) << "\n" << endl;

  vector<int> test5{1,1,1,1,1};
  cout << "test5 = {1,1,1,1,1};" << "\n" << endl;
  cout << "solution(test5) = " << solution(test5) << "\n" << endl;

  vector<int> test6{1,1,1,1,1,0};
  cout << "test6 = {1,1,1,1,1,0};" << "\n" << endl;
  cout << "solution(test6) = " << solution(test6) << "\n" << endl;
  
  return 0;
}
