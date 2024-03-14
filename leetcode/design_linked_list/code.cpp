#include <iostream>
#include <assert.h>

class MyLinkedList {
    struct Node
    {
        int val;
        Node *next;
        Node(int val)
        {
            this->val = val;
            this->next = nullptr;
        }
    };
    int len;
    Node *head;
public:
    MyLinkedList() {
        len = 0;
        head = nullptr;
    }
    
    int get(int index) {
        if(index >= len)
        {
            return -1;
        }
        Node *temp = head;
        while(index--)
        {
            temp = temp->next;
        }
        return temp->val;
    }
    
    void addAtHead(int val) {
        Node *temp = new Node(val);
        temp->next = head;
        head = temp;
        len++;
    }
    
    void addAtTail(int val) {
        if(len == 0)
        {
            addAtHead(val);
            return;
        }

        Node *temp = head;
        while(temp && temp->next)
        {
            temp = temp->next;
        }
        temp->next = new Node(val);
        len++;
    }
    
    void addAtIndex(int index, int val) {
        if(index > len)
        {
            return;
        }
        if(len == 0 || index == 0)
        {
            addAtHead(val);
            return;
        }
        
        Node *temp = head;
        while(index--> 1)
        {
            temp = temp->next;
        }
        Node *newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
        len++;
    }
    
    void deleteAtIndex(int index) {
        if(index == 0)
        {
            head = head->next;
            len--;
            return;
        }

        if(index >= len)
        {
            return;
        }
        Node *temp = head;
        while(index-- > 1)
        {
            temp = temp->next;
        }
        temp->next = temp->next->next;
        len--;
    }
};

int main()
{
    MyLinkedList myLinkedList;
    myLinkedList.addAtHead(1);
    myLinkedList.addAtTail(3);
    myLinkedList.addAtIndex(1, 2);
    assert(myLinkedList.get(1) == 2);
    myLinkedList.deleteAtIndex(1);
    assert(myLinkedList.get(1) == 3);
    return 0;
}