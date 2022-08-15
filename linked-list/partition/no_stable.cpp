#include "../linked_list.h"
#include<iostream>
using namespace std;

class Sol: public LinkedList{
    public:
        Sol():LinkedList(){};
        void partition(int k);
};

void Sol::partition(int k){
    Node *n1 = head;
    Node *n2 = head;

    while(head != nullptr){
        Node *next = head->next;
        if(head->data < k){
            head->next = n1;
            n1 = head;
        }else{
            n2->next = head;
            n2 = n2->next;
        }
        head = next;
    }
    n2->next = nullptr;
    head = n1;
}

int main(){
    Sol *linkedList = new Sol();
    linkedList->appendToTail(3);
    linkedList->appendToTail(5);
    linkedList->appendToTail(8);
    linkedList->appendToTail(5);
    linkedList->appendToTail(10);
    linkedList->appendToTail(2);
    linkedList->appendToTail(1);
    cout<<"Linked list before partition: "<<endl;
    linkedList->display();
    linkedList->partition(5);
    cout<<"Linked list after partition: "<<endl;
    linkedList->display();
    return 0;
}