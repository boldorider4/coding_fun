#include <algorithm>
#include <iostream>

struct boom {
  int x;
  struct boom* l;
  struct boom* r;
  boom() : x(0), l(nullptr), r(nullptr) {};
};

using boomKnot = struct boom;

int boom_sight(boomKnot* n, int max) {
  if (n == nullptr) return 0;
  max = std::max(max, n->x);
  int spotted = boom_sight(n->l, max) + boom_sight(n->r, max);

  if (n->x >= max) {
    spotted++;
  }

  return spotted;
}

int boom_sight_helper(boomKnot* n) {
  if (n == nullptr) return -1;
  int current_spot = 0;
  return boom_sight(n, current_spot);
}

int main() {
  boomKnot node0;
  node0.x = 5;
  boomKnot node1;
  node1.x = 3;
  boomKnot node2;
  node2.x = 20;
  boomKnot node3;
  node3.x = 21;
  boomKnot node4;
  node4.x = 10;
  boomKnot node5;
  node5.x = 1;

  node0.l = &node1;
  node0.r = &node4;
  node1.l = &node2;
  node1.r = &node3;
  node4.l = &node5;

  std::cout << "boom sight is " << boom_sight_helper(&node0) << std::endl;

  return 0;
}
