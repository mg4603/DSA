#include<iostream>
using namespace std;

class Node{
    int data;
    Node *next;
    public:
        Node(int data);
        void appendToTail(int data);
        void display();
        int kthToLast(Node* n, int k);
        Node* kthToLast(Node* n, int k, int &i);
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

Node* Node::kthToLast(Node* n, int k, int &i){
    if(n == NULL){
        return NULL;
    }
    Node* n1 = kthToLast(n->next, k, i);
    i++;
    if(i == k){
        return n;
    }
    return n1;
}
int Node::kthToLast(Node*n, int k){
    int i(0);
    Node* res = this->kthToLast(n, k, i);
    return res->data;
}

int main(){
    Node* head = new Node(0);
    head->appendToTail(1);
    head->appendToTail(2);
    head->appendToTail(3);
    head->appendToTail(4);
    head->appendToTail(5);
    cout<<"2nd last element of the linked list is:"<<head->kthToLast(head, 2)<<endl;
    return 0;
}