#include<iostream>
#include<stack>
using namespace std;

template <typename T>
class Queue{
    stack<T> oldest;
    stack<T> newest;
    
    public:
        Queue();

        void push(T value){
            newest.push(value);
        }

        
        
};

int main(){
    return 0;
}