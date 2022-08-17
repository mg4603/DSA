#include<iostream>
#include "../linked_list.h"
#include<cmath>
using namespace std;

class Sol{
    LinkedList *number1, *number2, *sum;
    public:
        Sol(int num1, int num2);
        void sumOfLists(Node *number1Ptr, Node *number2Ptr, int &carry);
        void sumOfLists();
        LinkedList* getSum(){
            return this->sum;
        }
        void padNumbers(int len1, int len2);
};
Sol::Sol(int num1, int num2){
    int lenNum1(floor(log10(num1)+1));
    int lenNum2(floor(log10(num2)+1));
    int lenNum1Temp(lenNum1);
    int lenNum2Temp(lenNum2);

    this->number1 = new LinkedList();
    this->number2 = new LinkedList();
    this->sum = new LinkedList();

    while(lenNum1Temp--){
        this->number1->appendToTail(num1/pow(10, lenNum1Temp));
        num1 = num1 % static_cast<int>(pow(10, lenNum1Temp));
    }
    while(lenNum2Temp--){
        this->number2->appendToTail(num2/pow(10,lenNum2Temp));
        num2 = num2 % static_cast<int>(pow(10, lenNum2Temp));
    }
    this->padNumbers(lenNum1,lenNum2);

}
void Sol::padNumbers(int len1, int len2){
    int padding(0);
    int paddingNum(0);
    if(len1 < len2){
        padding = len2 - len1;
        paddingNum = 1;
    }else{
        padding = len1 - len2;
        paddingNum = 2;
    }
    if(padding != 0){
        if(paddingNum == 1){
            while(padding--){
                this->number1->appendToHead(0);
            }
        }else{
            while(padding--){
                this->number2->appendToHead(0);
            }
        }
    }
}
void Sol::sumOfLists(Node *number1Ptr, Node *number2Ptr, int &carry){
    if(number1Ptr == nullptr && number2Ptr == nullptr && carry == 0){
        return;
    }
    sumOfLists(number1Ptr->next, number2Ptr->next, carry);
    int sumOfDigits(number1Ptr->data+number2Ptr->data+carry);
    carry = sumOfDigits /10;
    sumOfDigits %= 10;
    this->sum->appendToHead(sumOfDigits);
}
void Sol::sumOfLists(){
    int carry(0);
    this->sumOfLists(this->number1->getHead(), this->number2->getHead(), carry);
}
int main(){
    Sol *sol = new Sol(1, 295);
    sol->sumOfLists();
    sol->getSum()->display();
    return 0;
}