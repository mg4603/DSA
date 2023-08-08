#ifndef MIN_HEAP
#define MIN_HEAP

template <typename T>
class MinHeap
{
    std::vector<T> heap;
    void down_sift(int);
    void up_sift(int);

    public:
        MinHeap();
        MinHeap(std::vector<T>);
        bool push(T ele);
        T pop();
        void print_heap_array();    
};

#endif