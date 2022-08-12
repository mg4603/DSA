#include<iostream>
using namespace std;

class Node{
    int data;
    Node *next;
    public:
        Node(int data);
        void appendToTail(int data);
        int length();
        void kthToLast(int k);
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
int Node::length(){
    Node *n = this;
    int cnt(0);
    while(n!=NULL){
        cnt++;
        n = n->next;
    }
    return cnt;
}
void Node::kthToLast(int k){
    Node *n = this;
    int cnt(this->length()-k-1);
    while(cnt--){
        n = n->next;
    }
    cout<<n->data<<endl;
}
int main(){
    Node *head = new Node(0);
    head->appendToTail(1);
    head->appendToTail(2);
    head->appendToTail(3);
    head->appendToTail(4);
    head->appendToTail(5);
    cout<<"Last element is:"<<endl;
    head->kthToLast(0);
    return 0;
}