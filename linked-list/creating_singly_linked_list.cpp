#include<iostream>
using namespace std;

class Node{
    Node *next = NULL;
    int data;

    public: 
    Node(int d);
    void appendToTail(int d);
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

int main(){

    return 0;
}