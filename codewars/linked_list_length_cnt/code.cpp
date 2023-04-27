#include <assert.h>
#include <iostream>

struct Node{
    Node *next;
    int data;
    public:
        Node(){}
        Node(int i){
            this->data = i;
        }
};

int Length(Node *head){
    Node *ptr = head;
    int length(0);
    while(ptr != nullptr){
        length++;
        ptr = ptr->next;
    }
    return length;
}

int Count(Node *head, int val){
    Node *ptr = head;
    int count(0);

    while(ptr != nullptr){
        if(ptr->data == val){
            count++;
        }
        ptr = ptr->next;
    }
    return count;
}

void test1()
{
    Node *head = new Node;
    Node *n = head;
    for(int i = 0; i < 10; ++i)
    {
        n->next = new Node(i);
        n = n->next;
    }
    
    assert(Length(nullptr) == 0 );
    assert(Length(new Node(65)) == 1 );
    assert(Length(head) == 11 );
}

void test2(){
    Node *head = new Node;
    Node *n = head;
    for(int i = 0; i < 11; ++i)
    {
        n->next = new Node(i / 2);
        n = n->next;
    }
    assert(Count(nullptr, 0) == 0 );
    assert(Count(new Node, 0) == 1 );
    assert(Count(new Node, 5) == 0 );
    assert(Count(head, 0) == 3 );
    assert(Count(head, 4) == 2 );
    assert(Count(head, 5) == 1 );
}

int main(){
    test1();
    test2();
    return 0;
}