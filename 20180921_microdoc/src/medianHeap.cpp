#include "medianHeap"


template<class numType>
void medianHeap<numType>::insert(numType n) {
    if (minHeap.empty() && maxHeap.empty()) {
        minHeap.push(n);
    }
    
    //TBC
}

template<class numType>
numType medianHeap<numType>::median() {
    if (minHeap.size() > maxHeap.size()) {
        return minHeap.top();
    } else if (minHeap.size() < maxHeap.size()) {
        return maxHeap.top();
    }
    
    return (minHeap.top() + minHeap.top()) / 2;
}
