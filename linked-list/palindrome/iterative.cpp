#include<iostream>
#include "../linked_list.h"
using namespace std;

class Sol: public LinkedList{
    public:
        Sol(string str);
        bool isPalindrome();
};
Sol::Sol(string str){
    for(char a: str){
        this->appendToTail(a-'0');
    }
}
bool Sol::isPalindrome(){
    LinkedList* firstHalf = new LinkedList();
    Node *n1 = this->head, *n2 = this->head;
    while(n2 != nullptr && n2->next != nullptr){
        firstHalf->appendToHead(n1->data);
        n1 = n1->next;
        n2 = n2->next->next;
    }
    if(n2 != nullptr){
        n1 = n1->next;
    }
    n2 = firstHalf->getHead();
    while(n1 != nullptr){
        if(n1->data != n2->data)
        {
            return false;
        }
        n1 = n1->next;
        n2 = n2->next;
    }
    return true;
}

int main(){
    Sol *sol = new Sol("0121");
    cout<<"The number "<<(sol->isPalindrome()?"is a":"isn't a")<<" palindrome"<<endl;
    return 0;
}