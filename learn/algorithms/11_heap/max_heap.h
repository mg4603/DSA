#ifndef MAX_HEAP
#define MAX_HEAP

template <typename T>
class MaxHeap{
    std::vector<T> heap;
    void up_sift(int index);
    void down_sift(int index);

    public:
        MaxHeap();
        MaxHeap(std::vector<T>);
        bool push(T ele);
        T pop();
        void print_heap_array();
};

#endif