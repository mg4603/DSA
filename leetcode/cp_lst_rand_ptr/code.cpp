#include <iostream>
#include <assert.h>

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) 
    {
        if(head == nullptr)
        {
            return nullptr;
        }

        Node *ptr = head;
        while(ptr != nullptr)
        {
            Node *newNode = new Node(ptr->val);
            newNode->next = ptr->next;
            newNode->random = ptr->random;
            ptr->next = newNode;

            ptr = ptr->next->next;
        }
        
        Node *res = head->next;

        ptr = head->next;
        while(ptr != nullptr)
        {
            if(ptr->random)
            {
                ptr->random = ptr->random->next;
            }
            if(ptr->next)
            {
                ptr = ptr->next->next;
            }
            else
            {
                ptr = ptr->next;
            }
        }

        ptr = head;
        while(ptr != nullptr)
        {
            Node *temp = ptr->next;
            ptr->next = temp->next;
            ptr = ptr->next;
            if(ptr && ptr->next)
            {
                temp->next = ptr->next;
            }   
            else
            {
                temp->next = nullptr;
            }

        }
        return res;
    }
};

int main()
{
    return 0;
}