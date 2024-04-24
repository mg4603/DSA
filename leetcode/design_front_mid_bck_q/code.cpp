#include <iostream>
#include <assert.h>

class FrontMiddleBackQueue {
    struct Node
    {
        int val;
        Node *next;
        Node(int val)
        {
            this->val = val;
            this->next = nullptr;
        }
        Node(int val, Node *next)
        {
            this->val = val;
            this->next = next;
        }
    };
    Node *head;
    int len;
public:
    FrontMiddleBackQueue() {
        head = nullptr;
        len = 0;
    }
    
    void pushFront(int val) {
        Node *temp = new Node(val, head);
        head = temp;
        len++;
    }
    
    void pushMiddle(int val) {
        int mid = len / 2;
        if(mid == 0)
        {
            pushFront(val);
            return;
        }
        Node *temp = head;
        while(mid-- > 1)
        {
            temp = temp->next;
        }
        Node *temp2 = new Node(val, temp->next);
        temp->next = temp2;
        
        len++;
    }
    
    void pushBack(int val) {
        if(!head)
        {
            pushFront(val);
            return;
        }
        Node *temp = head;
        while(temp->next)
        {
            temp = temp->next;
        }
        temp->next = new Node(val);
        len++;
    }
    
    int popFront() {
        if(!head)return -1;
        int val = head->val;
        head = head->next;
        len--;
        return val;
    }
    
    int popMiddle() {
        if(!head)return -1;
        int mid = (len - 1) / 2 ;
        len--;
        
        if(mid == 0)
        {
            int val = head->val;
            head = head->next;
            return val;
        }
        
        if(!head->next)
        {
            int val = head->val;
            head = nullptr;
            return val;
        }

        Node *temp = head;
        while(mid-- > 1)
        {
            temp = temp->next;
        }
        int val = temp->next->val;
        temp->next = temp->next->next;
        return val;
    }
    
    int popBack() {
        if(!head)return -1;

        len--;
        if(!head->next)
        {
            int val = head->val;
            head = nullptr;
            return val;
        }
        Node *temp = head;
        while(temp->next->next)
        {
            temp = temp->next;
        }
        int val = temp->next->val;
        temp->next = nullptr;;
        return val;
    }
};

int main()
{
    return 0;
}