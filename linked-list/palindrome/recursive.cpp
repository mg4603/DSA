#include<iostream>
#include "../linked_list.h"
using namespace std;

class Sol: public LinkedList{
    public:
        Sol(string str);
};

Sol::Sol(string str){
    for(char c: str){
        this->appendToTail(c-'0');
    }
}

int main(){

    return 0;
}