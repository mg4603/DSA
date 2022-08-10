#include<iostream>
using namespace std;

class Node{
    Node *next = NULL;
    int data;

    public: 
    Node(int d);
    void appendToTail(int d);
    void display();
};

Node::Node(int d){
    data = d;
}

void Node::appendToTail(int d){
    Node *newNode = new Node(d);
    Node *n = this;
    
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
int main(){
    Node *head = new Node(5);
    head->appendToTail(6);
    head->appendToTail(7);
    head->display();
    return 0;
}