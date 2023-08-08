#include <iostream>
#include <vector>

#include "max_heap.h"

template<typename T>
MaxHeap<T>::MaxHeap()
{

}

template <typename T>
MaxHeap<T>::MaxHeap(std::vector<T> vec)
{
    for(T ele: vec)
    {
        this->push(ele);
    }
}

template <typename T>
bool MaxHeap<T>::push(T ele)
{
    this->heap.push_back(ele);
    this->up_sift(this->heap.size() - 1);
    return true;
}

template <typename T>
T MaxHeap<T>::pop()
{
    if(this->heap.size() == 0)
    {
        throw "Size error: heap empty";
    }
    T largest_ele = this->heap.at(0);
    std::swap(this->heap[0], this->heap[this->heap.size() - 1]);

    this->heap.pop_back();
    this->down_sift(0);
    
    return largest_ele;
}

template <typename T>
void MaxHeap<T>::up_sift(int idx)
{
    int parentIdx((idx - 1) / 2);
    while(idx > 0 && this->heap[parentIdx] < this->heap[idx])
    {
        std::swap(this->heap[parentIdx], this->heap[idx]);
        idx = parentIdx;
        parentIdx = (idx - 1) / 2;
    }
}

template <typename T>
void MaxHeap<T>::down_sift(int idx)
{
    int largest(idx);
    int left_idx(idx * 2 + 1);
    int right_idx(idx * 2 + 2);

    if(left_idx < this->heap.size() && this->heap[left_idx] > this->heap[largest])
    {
        largest = left_idx;
    }

    if(right_idx < this->heap.size() && this->heap[right_idx] > this->heap[largest])
    {
        largest = right_idx;
    }

    if(largest != idx)
    {
        std::swap(this->heap[largest], this->heap[idx]);
        this->down_sift(largest);
    }

}

template <typename T>
void MaxHeap<T>::print_heap_array()
{
    for(T ele: this->heap)
    {
        std::cout << ele << ' ';
    }
    std::cout << std::endl;
}