#include<iostream>
using namespace std;

class Node{
    int data;
    Node *next;
    public:
        Node(int data);
        void appendToTail(int data);
        void display();
        int printKthElement(Node*n, int k);
};
Node::Node(int data){
    this->data = data;
}
void Node::appendToTail(int data){
    Node *n = this;
    Node *newNode = new Node(data);
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
int Node::printKthElement(Node *n, int k){
    if(n == NULL)
        return 0;
    
    int index(printKthElement(n->next, k)+1);
    if(index == k){
        cout<<n->data<<endl;
    }
    return index;
}

int main(){
    Node *head = new Node(0);
    head->appendToTail(1);
    head->appendToTail(2);
    head->appendToTail(3);
    head->appendToTail(4);
    head->appendToTail(5);
    cout<<"2nd last element is:";
    head->printKthElement(head, 2);
    return 0;
}