#include<unordered_set>
#include<iostream>
#include<string>
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

void Node::display(){
    Node *n = this;
    while(n != NULL){
        cout<<n->data<<endl;
        n = n->next;
    }
}

void Node::removeDups(){
    Node *n = this;
    Node *prev;
    unordered_set<int> uniqueSet;
    while(n != NULL){
        if(uniqueSet.find(n->data) != uniqueSet.end()){
            prev->next = n->next;
        }else{
            uniqueSet.insert(n->data);
        }
        prev = n;
        n = n->next;
    }
}

int main(){
    Node *head = new Node(0);
    head->appendToTail(1);
    head->appendToTail(2);
    head->appendToTail(3);
    head->appendToTail(3);
    head->appendToTail(4);
    cout<<"Linked list before de-duplication:"<<endl;
    head->display();
    head->removeDups();
    cout<<"Linked list after de-duplication"<<endl;
    head->display();
    return  0;
}