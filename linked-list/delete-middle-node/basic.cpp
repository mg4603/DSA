#include<iostream>
using namespace std;

class Node{
    int data;
    Node* next;
    public:
        Node(int data);
        void appendToTail(int data);
        void display();
        void deleteNode(int data);
};
Node::Node(int data){
    this->data = data;
}
void Node::appendToTail(int data){
    Node* n = this;
    Node* newNode = new Node(data);
    while(n->next != NULL){
        n = n->next;
    }
    n->next = newNode;
}
void Node::display(){
    Node *n = this;
    while(n != NULL){
        cout<<n->data<<endl;
        n = n->next;
    }
}
void Node::deleteNode(int data){
    Node *n = this;
    while(n->data != data){
        n = n->next;
    }

    Node* next = n->next;
    n->data = next->data;
    n->next = next->next;
    free(next);
}
int main(){
    Node *head = new Node(0);
    head->appendToTail(1);
    head->appendToTail(2);
    head->appendToTail(3);
    head->appendToTail(4);
    cout<<"Linked list before deletion: "<<endl;
    head->display();
    head->deleteNode(3);
    cout<<"Linked list after deletion: "<<endl;
    head->display();
    return 0;
}