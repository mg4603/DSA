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
};

LinkedList::LinkedList(){}

void LinkedList::appendToTail(int data){
    if(this->head == nullptr){
        this->head = new Node(data);
    }
    Node *n = this->head;
    Node *newNode = new Node(data);
    while(n->next != nullptr){
        n = n->next;
    }
    n->next = newNode;
}
void LinkedList::display(){
    Node *n = this->head;
    while(n != nullptr){
        std::cout<<n->data<<std::endl;
        n = n->next;
    }
}
