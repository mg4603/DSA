#include<iostream>
using namespace std;

class Node{
    int data;
    Node* next;
    public:
        Node(int data);
        void appendToChild(int data);
        void display();
        void partition(int partitionPnt);
};
Node::Node(int data){
    this->data = data;
}
void Node::appendToChild(int data){
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
void Node::partition(int partitionPnt){
    Node *n = this;
    Node *beforeStart=NULL,
            *beforeEnd=NULL, 
            *afterStart=NULL, 
            *afterEnd=NULL;
    while(n != NULL){
        if(n->data < partitionPnt){
            if(beforeEnd == NULL){
                beforeEnd = new Node(n->data);
            }else{
                beforeEnd->next = new Node(n->data);
                beforeEnd = beforeEnd->next;
            }
            if(beforeStart == NULL){
                beforeStart = beforeEnd;
            }
        }else{
            if(afterEnd == NULL){
                afterEnd = new Node(n->data);
            }else{
                afterEnd->next = new Node(n->data);
                afterEnd = afterEnd->next;
            }
            if(afterStart == NULL){
                afterStart = afterEnd;
            }
        }
        n = n->next;
    }
    beforeEnd->next = afterStart;
    this->data =  beforeStart->data;
    this->next = beforeStart->next;

}
int main(){
    Node *head = new Node(3);
    head->appendToChild(5);
    head->appendToChild(8);
    head->appendToChild(5);
    head->appendToChild(10);
    head->appendToChild(2);
    head->appendToChild(1);
    cout<<"linked list before partition:"<<endl;
    head->display();
    head->partition(5);
    cout<<"linked list after partition:"<<endl;
    head->display();
    return 0;
}