#include<iostream>
#include "../linked_list.h"
using namespace std;

class Sol: public LinkedList{
    public:
        Sol(string str);
        LinkedList* reverseAndClone();
        bool isEqual(LinkedList* list1, LinkedList* list2);
        bool isPalindrome();
};
Sol::Sol(string str){
    for(char a: str)
        this->appendToTail(a-'0');
}
LinkedList* Sol::reverseAndClone(){
    LinkedList *reverse = new LinkedList();
    Node* n = this->getHead();
    while(n!=nullptr){
        reverse->appendToHead(n->data);
        n = n->next;
    }
    return reverse;
}
bool Sol::isEqual(LinkedList* list1, LinkedList* list2){
    if(list1->getLength() != list2->getLength()){
        return false;
    }
    Node* n1 = list1->getHead(), *n2 = list2->getHead();
    while(n1 != nullptr && n2 != nullptr){
        if(n1->data != n2->data){
            return false;
        }
        n1 = n1->next;
        n2 = n2->next;
    }
    return true;
}
bool Sol::isPalindrome(){
    LinkedList* reverse = this->reverseAndClone();
    return this->isEqual(this, reverse);
}
int main(){
    Sol *sol = new Sol("0121");
    cout<<"Number"<<(sol->isPalindrome()?"is a ":"isn't a ")<<"palindrome"<<endl;
    return 0;
}