#include <vector>
#include <iostream>
#include <string>
#include <set>

void recursive_transitive_relation(unsigned int start_idx,
                                  std::vector<std::string>& zombies,
                                  std::set<unsigned int>& cluster) {
  auto it = zombies.begin()+start_idx;
  for (auto idx = start_idx+1; idx < it->length(); idx++) {
    if (cluster.find(idx) == cluster.end() && it->at(idx) == '1') {
      cluster.insert(idx);
      recursive_transitive_relation(idx, zombies, cluster);
    }
  }
}

int count_zompbie_clusters(std::vector<std::string>& zombies) {
  int count = 0;
  std::set<unsigned int> cluster;

  for (size_t n = 0; n < zombies.size(); n++) {
    if (cluster.find(n) == cluster.end()) {
      recursive_transitive_relation(n, zombies, cluster);
      if (!cluster.empty()) count++;
    }
  }

  return count;
};

int main() {
  std::vector<std::string> zombies(4);
  zombies[0] = "1100";
  zombies[1] = "1110";
  zombies[2] = "1110";
  zombies[3] = "0001";


  int count = count_zompbie_clusters(zombies);

  std::cout << "count = " << count << std::endl;
}
