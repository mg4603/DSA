# Quick sort

* Divide and conquer algorithm
* pick pivots and move them to their correct position in the array:  
    &emsp;&emsp;larger than any element to it's left and lower than or equal to  
    &emsp;&emsp;every element to it's right.
* shuffle list to prevent worst case time complexity $O(n^2)$
* strategies to pick pivot:
    * first element
    * last element 
    * middle element
    * median of three randomly chose elements
    * pick random pivot

## Partition
* Find the correct position of the element and put it there

        Partition(low, high)
        {
            pivot = A[high];
            i = low - 1;
            for(j = low; j < high; j++)
            {
                if(A[j] < pivot)
                {
                    i++;
                    swap(A[i], A[j]);
                }
            }
            swap(A[i + 1], A[high])
            return i + 1;
        }

## Quick Sort algorithm
* shuffle array before partitioning

        quick_sort(l, h)
        {
            shuffle_array();
            if(l < h)
            {
                j = partition(l, h);
                quick_sort(l, j - 1);
                quick_sort(j + 1, h);
            }
        }

## Analysis
### Time Complexity
**Best case:**  
* When pivot selected is the median on each pass.
* It can't be achieved deterministically.
$T(n) = O(nlogn)$

**Worst case:**
When pivot is on either the smallest or greatest element in the list on each  
pass.
$T(n) = O(n^2)$

**Average case:**
$T(n) = O(nlogn)$

### Space complexity:
* size of stack
**Best case:**  
$S(n) = O(logn)$  
**Worst case**  
$S(n) = O(n)$