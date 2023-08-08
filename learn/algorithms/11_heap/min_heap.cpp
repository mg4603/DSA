#include <vector>
#include <iostream>

#include "min_heap.h"

template <typename T>
MinHeap<T>::MinHeap()
{

}

template <typename T>
MinHeap<T>::MinHeap(std::vector<T> vec)
{
    for(T ele: vec)
    {
        this->push(ele);
    }
}

template <typename T>
void MinHeap<T>::print_heap_array()
{
    for(T ele: heap)
    {
        std::cout << ele <<  ' ';
    }
    std::cout << std::endl;
}

template <typename T>
bool MinHeap<T>::push(T ele)
{
    this->heap.push_back(ele);
    this->up_sift(this->heap.size() - 1);
    return true;
}

template <typename T>
T MinHeap<T>::pop()
{
    if(this->heap.size() == 0)
    {
        throw "Size error: heap empty";
    }

    T smallest = this->heap[0];
    std::swap(this->heap[0], this->heap[this->heap.size() - 1]);

    this->heap.pop_back();
    this->down_sift(0);
    return smallest;
}

template <typename T>
void MinHeap<T>::up_sift(int idx)
{
    int parent_idx((idx - 1) / 2);
    while(idx > 0 && this->heap[parent_idx] > this->heap[idx])
    {
        std::swap(this->heap[parent_idx], this->heap[idx]);
        idx = parent_idx;
        parent_idx = (idx - 1) / 2;
    }
}

template <typename T>
void MinHeap<T>::down_sift(int idx)
{
    int smaller_idx(idx);
    int left_idx((idx * 2 ) + 1);
    int right_idx((idx * 2) + 2);

    if(left_idx < this->heap.size() && this->heap[left_idx] < this->heap[smaller_idx])
    {
        smaller_idx = left_idx;
    }
    
    if(right_idx < this->heap.size() && this->heap[right_idx] < this->heap[smaller_idx])
    {
        smaller_idx = right_idx;
    }

    if(smaller_idx != idx)
    {
        std::swap(this->heap[smaller_idx], this->heap[idx]);
        down_sift(smaller_idx);
    }
}