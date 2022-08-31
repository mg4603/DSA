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

        virtual bool isOlderThan() = 0;
        
};

class Dog: public Animal{
    public:
        Dog(string n) : Animal(n){
        }
        bool isOlderThan(Animal* a){
            return this->getOrder() < a->getOrder();
        }
};

class Cat: public Animal{
    public:
        Cat(string n): Animal(n){}
        bool isOlderThan(Animal* a){
            return this->getOrder() < a->getOrder();
        }
};



class AnimalQueue{
    queue<Dog*> dogs;
    queue<Cat*> cats;
    int order = 0;
    public:
        void enqueue(Animal* a){
            a->setOrder(order);
            order++;

            if(Dog* dog = dynamic_cast<Dog*>(a)){
                dogs.push(dog);
            }else if(Cat* cat = dynamic_cast<Cat*>(a)){
                cats.push(cat);
            }
        }


        Animal* dequeueAny(){
            if(dogs.size() == 0){
                dequeueCats();
            }else if(cats.size() == 0){
                dequeueDogs();
            }

            Dog* dog = dogs.back();
            Cat* cat = cats.back();

            if(cat->isOlderThan(dog)){
                dequeueCats();
            }else if(dog->isOlderThan(cat)){
                dequeueDogs();
            }


        }

};

int main(){
    return 0;
}