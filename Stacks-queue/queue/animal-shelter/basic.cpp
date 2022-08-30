#include<iostream>
#include<queue>
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

        bool isOlderThan(Animal a){
            return this->order < a.order;
        }
};

class Dog: public Animal{
    public:
        Dog(string n) : Animal(n){
        }
};

class Cat: public Animal{
    public:
        Cat(string n): Animal(n){}
};

class AnimalQueue{
    queue<Dog> dogs;
    queue<Cat> cats;
    int order = 0;
    

};

int main(){
    return 0;
}