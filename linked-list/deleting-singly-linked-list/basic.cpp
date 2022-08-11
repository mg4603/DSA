#include<iostream>
using namespace std;

class Node{
    Node *next = NULL;
    int data;

    public:
    Node(int data);
    void deleteNode(int data);
    void display();
    void appendToTail(int data);
};
Node::Node(int d){
    data = d;
}
void Node::appendToTail(int data){
    Node *n = this;
    Node *newNode = new Node(data);

    while(n->next != NULL){
        n = n->next;
    }
    n->next = newNode;
}

void Node::deleteNode(int data){
    Node *n = this;
    while(n->next->data!=data){
        n = n->next;
    }
    Node *nodeToDelete = n->next;
    n->next = n->next->next;
    free(nodeToDelete);
}
void Node::display(){
    Node *n = this;
    while(n != NULL){
        cout<<n->data<<endl;
        n = n->next;
    }
}

int main(){
    Node *head=new Node(0);
    head->appendToTail(1);
    head->appendToTail(2);
    head->appendToTail(3);
    cout<<"Linked list after creation"<<endl;
    head->display();
    head->deleteNode(2);
    cout<<"Linked list after deletion"<<endl;
    head->display();
    return 0;
}