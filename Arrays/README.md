
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