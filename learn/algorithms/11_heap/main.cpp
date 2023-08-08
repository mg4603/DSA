#include <iostream>
#include <vector>

#include "max_heap.h"
#include "max_heap.cpp"

#include "min_heap.h"
#include "min_heap.cpp"

template <typename T>
std::vector<T> & heap_sort_min(std:: vector<T> & vec)
{
    MinHeap<T> heap(vec);
    vec.clear();
    try
    {
        while(true)
        {
            vec.push_back(heap.pop());
        }
    }
    catch(...)
    {

    }
    return vec;
}

template <typename T>
void print_vec(std::vector<T> vec)
{
    for(T ele: vec)
    {
        std::cout << ele << ' ';
    }
    std::cout << std::endl;
}

int main()
{
    std::cout << "Max Heap with elements 1, 2, 3, 4, 5:\n";
    MaxHeap<int> heap({1, 2, 3, 4 ,5});
    heap.print_heap_array();
    heap.pop();
    std::cout << "pop from max heap:\n";
    heap.print_heap_array();
    heap.pop();
    std::cout << "pop from max heap:\n";
    heap.print_heap_array();
    heap.push(15);
    std::cout << "push 15 to heap:\n";
    heap.print_heap_array();

    std::cout << "Min Heap with elements 1, 2, 3, 4, 5:\n";
    MinHeap<int> min_heap({1, 2, 3, 4, 5});
    min_heap.print_heap_array();
    min_heap.pop();
    std::cout << "pop from min heap:\n";
    min_heap.print_heap_array();
    min_heap.pop();
    std::cout << "pop from min heap:\n";
    min_heap.print_heap_array();
    min_heap.push(15);
    std::cout << "push 15 to heap:\n";
    min_heap.print_heap_array();

    std::vector<int> vec = {1, 5, 7, 2, 4, 6};
    std::cout << "Heap sort with min heap:\n";
    std::cout << "Before: ";
    print_vec<int>(vec);
    vec = heap_sort_min(vec);
    std::cout << "After: ";
    print_vec<int>(vec);
    return 0;
}