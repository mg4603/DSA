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

        T pop(){
            if(oldest.empty()){
                while(!newest.empty()){
                    T value = newest.top();
                    newest.pop();
                    oldest.push(value);
                }
            }
            T firstValue = oldest.top();
            oldest.pop();
            return firstValue;
        }

        T peek(){
            if(oldest.empty()){
                while(!newest.empty()){
                    T value = newest.top();
                    newest.pop();
                    oldest.push(value);
                }
            }
            T firstValue = oldest.top();
            return firstValue;
        }
        
};

int main(){
    return 0;
}