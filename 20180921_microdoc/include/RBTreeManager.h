#pragma once

#include "RBTree.h"
#include <unordered_map>
#include <string>


class RBTreeManager {

 public:
  RBTreeManager() = default;
  ~RBTReeManager() = default;
  void insertValue(SuperInt);
  void deleteValue(SuperInt);
  
 private:
  const unsinged int maxTreeSize = 1000;
  std::unordered_map<std::string, std::string> treePages;
};
