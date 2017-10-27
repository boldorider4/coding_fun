#include <iostream>
#include <cstddef>
#include <algorithm>

using namespace std;

class Node{
public:
  int data;
  Node *left;
  Node *right;
  Node(int d){
    data = d;
    left = NULL;
    right = NULL;
  }
};

class Solution {
public:
  Node* insert(Node* root, int data) {
    if(root == NULL) {
      return new Node(data);
    }
    else {
      Node* cur;
      if(data <= root->data){
        cur = insert(root->left, data);
        root->left = cur;
      }
      else{
        cur = insert(root->right, data);
        root->right = cur;
      }

      return root;
    }
  }

  int height(Node* root) {
    if (root != NULL)
    {
      if (root->left == NULL && root->right == NULL)
        return 0;

      /* explore left */
      int left_depth = height(root->left) + 1;
      /* explore right */
      int right_depth = height(root->right) + 1;

      return max(left_depth, right_depth);
    }

    return 0;
  }
};

int main() {
  Solution myTree;
  Node* root = NULL;
  int t;
  int data;

  cin >> t;

  while(t-- > 0){
    cin >> data;
    root = myTree.insert(root, data);
  }
  int height = myTree.height(root);
  cout << height << endl;

  return 0;
}
