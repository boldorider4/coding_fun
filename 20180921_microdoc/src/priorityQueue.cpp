#include <iostream>
#include <vector>
#include <queue>


struct intComparatorGreater {
  bool operator()(int arg1, int arg2) {
    return (arg1 >= arg2);
  }
};


struct intComparatorSmaller {
  bool operator()(int arg1, int arg2) {
    return (arg1 <= arg2);
  }
};


int priorityQueue() {

  std::vector<int> input({1, 22, 100, 21, 10});
  std::priority_queue<int, std::deque<int>, intComparatorGreater> minHeap;
  std::priority_queue<int, std::deque<int>, intComparatorSmaller> maxHeap;

  for (auto intVal : input) {
    minHeap.push(intVal);
  }

  std::cout << "Priority queue: Min Heap" << std::endl;

  while (minHeap.size() > 0) {
    std::cout << minHeap.top() << std::endl;
    minHeap.pop();
  }

  for (auto intVal : input) {
    maxHeap.push(intVal);
  }

  std::cout << std::endl << "Priority queue: Max Heap" << std::endl;

  while (maxHeap.size() > 0) {
    std::cout << maxHeap.top() << std::endl;
    maxHeap.pop();
  }

  return 0;
}
