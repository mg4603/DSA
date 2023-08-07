# Heap

## Array representation of Binary Tree
If a node is at index i:
* It's left child is at $((2 \times i) + 1)$
* It's right child is at $((2 \times i) + 2)$
* It's parent is at $\lfloor \frac{i-1}{2} \rfloor$

### Full Binary Tree
A binary tree of height h that has $2^h - 1$ nodes.

## Complete Binary Tree
A binary tree that doesn't have any gaps when represented as array. Every full  
binary tree is also a complete binary tree.

A complete binary tree can be defined as a full binary tree of height (h-1),  
with elements in the $h^{th}$ level filled in from left to right.

The height of a complete binary tree will be at most $\lfloor log(n) \rfloor + 1 $

## Heap
* All heaps must be complete binary tree
* Max heap - all descendants must be lesser than or equal to their parent
* Min heap - all descendants must be greater than or equal to their parent.

## Insert & Delete
### Insert in Max Heap
1. Add new element to the end of the array
2. Compare the new element with parent and swap if it is larger
3. Repeat step 2 until the new element is in it's correct position  

**Time Complexity**:
* Best case: $O(1)$
* Average and worst case: $O(logn)$

### Delete in Max Heap
* Only the root can be deleted
1. Remove the root element and replace it with the last leaf of the complete  
    binary tree
2. Compare the new root with it's children and swap if it is smaller
3. Repeat step 2 until the last element is in it's correct position.

**Time Complexity**
* Best, average and worst case: $O(logn)$

## Heap Sort
1. Create a min or max heap
2. Delete the root element sequentially till the heap is empty
3. The deleted elements will be in sorted order - ascending for min-heap and  
descending for max-heap

**Time Complexity**:  
$O(nlogn)$

### Create heap (max)
1. Insert element at end of the heap
2. Compare the inserted element with it's ancestor and swap them if it is  
greater
3. Repeat step 2 until the element's correct position is found

**Time Complexity**:  
$(nlogn)$

## Heapify
Performed after insertion and deletion

## Priority Queue
* Elements are inserted with a priority
* The element with the highest priority is removed first.
* smaller number - higher priority can be modeled using a min heap
* larger number - higher priority can be modeled using a max heap