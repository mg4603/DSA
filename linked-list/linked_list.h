#include<limits>
#include<iostream>
struct Node{
    int data;
    Node* next;
    Node(int data);
};
Node::Node(int data){
    this->data = data;
}
class LinkedList{
    protected:
        Node* head;
    public:
        LinkedList();
        void appendToTail(int data);
        void display();
        Node* getHead();
        int getLength();
        void appendToHead(int data);
};

LinkedList::LinkedList(){}

void LinkedList::appendToTail(int data){
    if(this->head == nullptr){
        this->head = new Node(data);
        return;
    }
    Node *n = this->head;
    Node *newNode = new Node(data);
    while(n->next != nullptr){
        n = n->next;
    }
    n->next = newNode;
}
void LinkedList::appendToHead(int data){
    if(this->head == nullptr){
        this->head = new Node(data);
        return;
    }
    Node *n = new Node(data);
    n->next = this->head;
    this->head = n;
}
void LinkedList::display(){
    Node *n = this->head;
    while(n != nullptr){
        std::cout<<n->data<<std::endl;
        n = n->next;
    }
}

Node* LinkedList::getHead(){
    return this->head;
}

int LinkedList::getLength(){
    int length(0);
    Node* n = this->head;
     while(n != nullptr){
        length++;
        n = n->next;
     }
     return length;
}