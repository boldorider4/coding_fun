#pragma once
#include <queue>


template<class numType>
class medianHeap {
    
public:
    medianHeap() = default;
    ~medianHeap() = default;
    medianHeap(medianHeap&) = delete;
    medianHeap(medianHeap&&) = delete;
    
    /* public interface */
    void insert(numType);
    numType median();
    
private:
    
    /* comparators used for priority queues */
    struct intComparatorGreater {
        bool operator()(numType arg1, numType arg2) {
            return (arg1 >= arg2);
        }
    };
    
    struct intComparatorSmaller {
        bool operator()(numTypet arg1, numType arg2) {
            return (arg1 <= arg2);
        }
    };
    
    /* min heap and max heap */
    std::priority_queue<numType, Compare=intComparatorGreater> minHeap;
    std::priority_queue<numType, std::deque<numType>, intComparatorSmaller> maxHeap;
}
