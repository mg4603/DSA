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

## Runner technique(second pointer)
- Iterate through a linked list with two pointers simultaneously
- One of the pointers is usually ahead of the other by:
    - a fixed amount
    - hopping multiple nodes for each node that the slow node iterates through
- example:
    - suppose a linked list a1->a2->a3->a4->...->an->b1->b2->b3->b4->...->bn
        is to be rearranged as  a1->b1->a2->b2->a3->b3->...->an->bn in a situation
        where length of linked list is not know but it is known that length is even
            - iterate through the linked list with two pointers p1 and p2 with p1
                hopping two nodes for every node that p2 hops
            - when p1 hits the end of the linked list, p2 will have reached the 
                mid-point
            - move p1 back to the beginning and begin weaving the elements


    