#include<iostream>
#include<queue>
using namespace std;


class Animal{
    int order;
    string name;
    virtual void fun1() = 0;
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
        
        string getName(){
            return this->name;
        }
        // virtual bool isOlderThan() = 0;
        
};

class Dog: public Animal{
    void fun1(){

    }
    public:
        Dog(string n) : Animal(n){
        }
        bool isOlderThan(Animal* a){
            return this->getOrder() < a->getOrder();
        }
};

class Cat: public Animal{
    void fun1(){

    }
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

        Cat* dequeueCats(){
            if(cats.size() == 0){
                throw "No cats available";
            }
            Cat* cat = cats.front();
            cats.pop();
            return cat;
        }

        Dog* dequeueDogs(){
            if(dogs.size() == 0){
                throw "No dogs available";
            }
            Dog* dog = dogs.front();
            dogs.pop();
            return dog;
        }

        Animal* dequeueAny(){
            if(dogs.size() == 0){
                return dequeueCats();
            }else if(cats.size() == 0){
                return dequeueDogs();
            }

            Dog* dog = dogs.front();
            Cat* cat = cats.front();

            if(cat->isOlderThan(dog)){
                return dequeueCats();
            }else if(dog->isOlderThan(cat)){
                return dequeueDogs();
            }

            return nullptr;
        }

};

int main(){
    Dog* dog1 = new Dog("Dog1");
    Dog* dog2 = new Dog("Dog2");
    AnimalQueue* aq = new AnimalQueue();
    aq->enqueue(dog1);
    aq->enqueue(dog2);
    Animal* deqAni = aq->dequeueAny();
    cout<<deqAni->getName()<<endl;
    return 0;
}