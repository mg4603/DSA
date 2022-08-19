
# Stack

## What?
- A data structure that follows the LIFO (Last-in First-out) or
  FILO (First-in Last-out) structure.
- Insertion and deletion occur at the same end

## Operations:
- push():
  - add an element to the top of the stack
  - if the stack is full, then it is said to be an overflow condition
  - time complexity: O(1)
        begin
            if stack is full
                return
            endif
            else
                increment top
                assign value to stack[top]
                end else
        end 

- pop():
    - remove an element from the top of the stack
    - time complexity: O(1)
        ```
        begin
            if stack is empty
                return
            endif
            else
                store value of stack[top]
                decrement top
                return stored value of stack[top]
            end else
        end
        ```
- top():
    - returns the element at the top of the stack
    - time complexity: O(1)
    ```
    begin
        return stack[top]
    end
    ```
- isEmpty():
    - checks if the stack is empty
    - time complexity: O(1)
        ```
        begin
            if top < 1
                return true
            end if
            else
                return false
            end else
        end
        ```
- size():
    - returns the size of the stack
    - time complexity: O(1)
        ```
        begin
            if top < 1
                return 0
            end if
            else
                return top + 1
            end else 
        end
        ```


## Types of Stacks
- **Register Stack:**
    - memory element present in a memory unit
    - can only handle a small amount of data
    - limited height as size of register stack is very small compared to memory
- **Memory Stack:** 
    - What is traditionally referred to as a stack
    - can handle a large amount of memory data
    - height is flexible as it occupies a large amount of memory data

## Applications:
    - Balancing of symbols
    - Infix to pre/post-fix conversion
    - Redo/undo features
    - forward or backward in browsers
    - Tower of hanoi
    - tree traversal
    - stock span problems
    - histogram problems
    - Backtracking algorithm
    - Graph algorithms:
        - Topological sorting
        - Strongly Connected Components
    - Memory Management:
        - program stack
    - String reversal

# Queue

- Implements a FIFO(first-in first-out) ordering.
- Items are removed for a data structure in the same order that they are added


## Operations:

- add(item): Add an item to the end of the queue
- remove(): remove the first item of the queue
- peek(): return the first element of the queue
- isEmpty(): Return true iff the queue is empty
