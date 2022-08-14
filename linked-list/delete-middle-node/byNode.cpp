#include<iostream>
using namespace std;

class Node{
    int data;
    Node *next;
    public:
        Node(int data);
        Node* appendToTail(int data);
        void deleteNode(Node* n);
        void display();
};

Node::Node(int data){
    this->data = data;
}
Node* Node::appendToTail(int data){
    Node *n = this;
    Node *newNode = new Node(data);
    while(n->next != NULL){
        n = n->next;
    }
    n->next = newNode;
    return n->next;
}
void Node::deleteNode(Node* n){
    if(n == NULL){
        return;
    }
    if(n->next == NULL){
        return;
    }

    Node *next = n;
    next->data = n->next->data;
    next->next = n->next->next;
}
void Node::display(){
    Node *n = this;
    while(n != NULL){
        cout<<n->data<<endl;
        n = n->next;
    }
}

int main(){
    Node* head = new Node(0);
    head->appendToTail(1);
    head->appendToTail(2);
    Node* nodeToDelete = head->appendToTail(3);
    head->appendToTail(4);
    head->appendToTail(5);
    cout<<"Linked list before deletion:"<<endl;
    head->display();
    head->deleteNode(nodeToDelete);
    cout<<"Linked List after deletion:"<<endl;
    head->display();
    return 0;
}