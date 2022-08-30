#include<iostream>
using namespace std;


class Animal{
    int order;
    string name;
    public:
        Animal(string n){
            name = n;    
        }
        void setOrder(int order){
            this->order = order;
        }
        int getOrder(){
            return this->order;
        }
};

int main(){
    return 0;
}