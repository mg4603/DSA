# Linked List
- A sequence of nodes
- singly linked list - each node points to the next
- doubly linked list - each node points to both the previous and next node
- not constant time access 
- constant time insertion at beginning of list

## Creating a Linked List
- Insertion to the beginning takes constant time
- Insertion at the end takes O(n) time

## Deleting a node from singly linked list
- singly linked list:
    - find the node to be deleted
    - point the previous node to the next node
    - delete the current node
- doubly linked list:
    - find the node to be deleted
    - point the previous node's forward link to the next node
    - point the next node's backward link to the previous node
    - delete the current node