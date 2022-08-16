#include<iostream>
#include "../linked_list.h"
using namespace std;

class Sol{
    LinkedList *number1, *number2, *sum;
    public:
        Sol(int num1, int num2);
        void sumOfLists();
        LinkedList* getSum(){
            return this->sum;
        }
};
Sol::Sol(int num1, int num2){
    this->number1 = new LinkedList();
    this->number2 = new LinkedList();
    this->sum = new LinkedList();
    while(num1){
        this->number1->appendToTail(num1%10);
        num1 /= 10;
    }
    while(num2){
        this->number2->appendToTail(num2%10);
        num2 /= 10;
    }
};
void Sol::sumOfLists(){
    Node* n1 = this->number1->getHead();
    Node* n2 = this->number2->getHead();
    int carry(0), digitSum(0);
    while(n1 != nullptr && n2 != nullptr){
        digitSum = n1->data+n2->data+carry;
        carry = digitSum / 10;
        this->sum->appendToTail(digitSum%10);
        n1 = n1->next;
        n2 = n2->next;
    }
    while(n1 != nullptr){
        this->sum->appendToTail(n1->data);
        n1 = n1->next;
    }
    while(n2 != nullptr){
        this->sum->appendToTail(n2->data);
        n2 = n2->next;
    }
}
int main(){
    Sol *sol = new Sol(617, 295);
    sol->sumOfLists();
    sol->getSum()->display();
    return 0;
}