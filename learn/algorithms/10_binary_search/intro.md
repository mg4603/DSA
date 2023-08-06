# Binary Search

## Algorithm
1. Check if the mid element of a sorted array is the key you are searching for.
2. If the key is larger than the mid element repeat step 1 for the second half  
    of the array.
3. else repeat step 1 for the fist half of the array.
4. Repeat steps 1-3 until the mid element is the key you are searching for or  
the size of the sub-array is one. If the element in the sub-array of size 1 is  
not the key you are searching for, the element doesn't exist in the array,  
otherwise return the index at which the key is found.

## Time complexity
$T(n) = T(n/2) + 1 = O(logn)$

### Best case complexity:
$T(n) = O(1)$

### Worst case complexity:
$T(n) = O(logn)$

### Average case complexity:
$T(n) = O(logn)$

## Note
* List must be in sorted order

