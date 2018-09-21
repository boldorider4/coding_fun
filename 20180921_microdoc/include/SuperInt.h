#pragma once

#include <vector>
#include <iostream>


struct SuperInt {
  std::vector<int> value;
  bool operator<(SuperInt& arg);
  bool operator>(SuperInt& arg);
  bool operator==(SuperInt& arg);
  bool operator<=(SuperInt& arg);
  bool operator>=(SuperInt& arg);
};

std::ostream& operator<<(std::ostream& os, SuperInt& arg);
