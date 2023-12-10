#include <iostream>
#include <assert.h>

class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};

class Solution {
public:
    Node* flatten(Node* head) 
    {
        Node *curr = head;
        while(curr != nullptr)
        {
            if(curr->child)
            {
                Node * next = curr->next;

                curr->next = curr->child;
                curr->child = nullptr;
                curr->next->prev = curr;

                Node *child_ptr = curr->next;
                while(child_ptr->next != nullptr)
                {
                    child_ptr = child_ptr->next;
                }
                child_ptr->next = next;
                if(next)
                next->prev = child_ptr;
            }
            curr = curr->next;
        }
        return head;
    }
};

int main()
{
    return 0;
}