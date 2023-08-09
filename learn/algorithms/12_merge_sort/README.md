# Merge Sort
* Divide and conquer algorithm
* A small problem, one that doesn't have to be subdivided, is one with only  
    one element.

## Merge 
* Combining two sorted lists into a single list
    
        merge(A, B)
        {
            i = 0, j = 0, k = 0;
            while(i < size of A && j < size of B)
            {
                if(A[i] < B[j])
                {
                    C[k] = A[i];
                    i++;
                    k++;
                }
                else
                {
                    C[k] = B[j];
                    j++;
                    k++;
                }
            }
            while(i < size of A)
            {
                C[k] = A[i];
                i++;
                k++;
            }
            while(j < size of B)
            {
                C[k] = B[j];
                j++;
                k++;
            }
               return C;
        }   

**Time Complexity:**  
$T(n) = O(n + m)$
where,
* n = number of elements in first list
* m = number of elements in second list


## Merge Sort Algorithm
1. Divide the array into two sub arrays 
2. Call merge sort on the two sub-arrays
3. Recursively call steps 1 and two while size of sub-array is larger than 1.
4. Merge the two sorted sub-arrays

    merge_sort(l, h)
    {
        if(l < h)
        {
            mid = (l + h) / 2;
            merge_sort(l, mid);
            merge_sort(mid + 1, h);
            merge(l, mid, h);
        }
    }

**Time Complexity:**  
$T(n) = O(n log n)$


## Two Way Merge Sort
* Iterative Algorithm
1. Assume the list to be sorted, to be n lists of 1 element each.
2. Perform 2 way merge sequentially until the size of merged list is n.

**Time Complexity:**
$T(n) = O(nlogn)$


## Analysis
### Pros
* suitable for large size list
* suitable for linked list
* supports external sorting
* stable(order of duplicates is maintained)

### Cons
* Requires auxillary space (not an in-place algorithm):
    * $n$ for data.
    * $logn$ for stack.
    * $O(n)$
* no small problem
* slower for small size list as compared to other sorts
* Recursive - depends on stack which is of height $log(n)$