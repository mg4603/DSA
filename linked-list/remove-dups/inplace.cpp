#include<iostream>
using namespace std;

class Node{
    int data;
    Node *next;
    
    public:
        Node(int data);
        void appendToTail(int data);
        void removeDups();
        void display();
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
void Node::removeDups(){
    Node *n1 = this;
    Node *n2, *prev, *nodeToDelete;
    while(n1 != NULL){
        n2 = n1->next;
        prev = n1;
        while(n2 != NULL){
            if(n2->data == n1->data){
                nodeToDelete = n2;
                prev->next = n2->next;
                prev = n2->next;
                free(nodeToDelete);
            }else{
                prev = n2;
            }
            n2 = n2->next;
        }
        n1 = n1->next;
    }
}
void Node::display(){
    Node *n = this;
    while(n != NULL){
        cout<<n->data<<endl;
        n = n->next;
    }
}

int main(){
    Node *head = new Node(0);
    head->appendToTail(0);
    head->appendToTail(1);
    head->appendToTail(2);
    head->appendToTail(3);
    head->appendToTail(3);
    head->appendToTail(4);
    cout<<"Display linked list before de-duplication"<<endl;
    head->display();
    head->removeDups();
    cout<<"Display linked list after de-duplication"<<endl;
    head->display();
    return 0;
}