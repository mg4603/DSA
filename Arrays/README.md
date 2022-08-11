to do:
- hashtable 
- rotate_matrix inplace


# Arrays

## What?
- Collection of items stored at contiguous memory locations.
- Storing multiple items of the same type together makes access easier:
    - The location of the first element is usually denoted by the array name
    - The location of other elements in memory can be calculated by add the 
    offset to the base.
    - Location of next index in memory depends on datatype.

### Hash Tables?
- DS that maps keys to value for efficient lookup
- Implementation with arrays and link-list:
    - Compute the key's hash code 
        - There can be collisions between the hash codes as there are infinite number of keys and a finite number of hashes
    - map the hash code to an index in the array
        - eg: hash(key) % array_length
        - There can be multiple hash codes that map to the same index
    - store the key value pair in the linked list (of key-value pairs) at the index
    - during look-up:
        - hash the key 
        - calculate the index from the hash
        - store the key-value pair in the linked list at the index

- worst case complexity in case of high collisions : O(N) where N is the number of keys
- In case of minium collisions the complexity is O(1) => good implementation

### Vectors
- Array-like data structure that offers dynamic resizing. 
- Re-sizes itself as needed while still providing O(1) access.
- When the array is full, it increases by a factor of K, i.e., when the array of size N is full it's size becomes K * N
- Each resizing takes O(N) time, where N is the number of elements when the array re-sizes
    - Resizing however is rare enough that amortized insertion time is still O(1)
- For GCC, K = 2
- Why is amortized insertion time O(1):
    - Working backward for a size of N and K = 2:
        - final capacity increase : n/2 elements to copy
        - previous capacity increase: n/4 elements to copy  
        - previous capacity increase: n/8 elements to copy
        - ...
        - second capacity increase: 2 elements to copy
        - first capacity increase: 1 element to copy
    - Therefore total number of operations to insert N elements is roughly N+N/2+N/4+N/8+....+2+1
    - which is approximately equal 2N => therefore work to insert 1 element is approximately 2 => O(1)
