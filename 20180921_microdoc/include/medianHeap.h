#include <queue>


class medianHeap {
    
public:
    medianHeap() = default;
    ~medianHeap() = default;
    medianHeap(medianHeap&) = delete;
    
private:
    
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
    
    std::priority_queue<int, Compare=intComparatorGreater> minHeap;
}
