# Binary Heaps
## Intro:
- Min-heaps(ascending) and max-heaps(descending)
- complete binary trees
- each node is smaller than it's children
- root in the min element in the tree

## Operations:
### Insert
- Elements are inserted at the bottom, at the rightmost spot to maintain 
the complete tree property
- Swap the element with it's parent till the correct position is found
(bubble-up)
- O(log n)
### Extract Min
- The min element in the tree is at the root
- Set the right bottom most element as the root and then bubble-down 
said element to find it's correct position
- O(log n)


