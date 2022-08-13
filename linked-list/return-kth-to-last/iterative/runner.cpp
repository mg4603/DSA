//Uses the runner method
#include<iostream>
using namespace std;

class Node{
    int data;
    Node* next;
    public:
        Node(int data);
        void appendToTail(int data);
        void display();
        int kthToLast(int k);
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
int Node::kthToLast(int k){
    Node* p1 = this, *p2 = this;
    while(k--){
        p1 = p1->next;
    }
    while(p1 != NULL){
        p1 = p1->next;
        p2 = p2->next;
    }
    return p2->data;
}

int main(){
    Node* head = new Node(0);
    head->appendToTail(1);
    head->appendToTail(2);
    head->appendToTail(3);
    head->appendToTail(4);
    cout<<"last element is: "<<head->kthToLast(1)<<endl;
    return 0;
}