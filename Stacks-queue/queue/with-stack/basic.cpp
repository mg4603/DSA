#include<iostream>
#include<stack>
using namespace std;

template <typename T, typename Q>
class Queue{
    stack<T> oldest;
    stack<T> newest;
    
    void shiftStack(){
        if(oldest.empty()){
            while(!newest.empty()){
                T value = newest.top();
                newest.pop();
                oldest.push(value);
            }
        }
    }

    public:
        Queue(){};

        Q size(){
            return oldest.size() + newest.size();
        }

        void push(T value){
            newest.push(value);
        }

        T pop(){
            this->shiftStack();
            if(this->size() == 0){
                throw "Queue empty";
            }
            T firstValue = oldest.top();
            oldest.pop();
            return firstValue;
        }

        T peek(){
            this->shiftStack();
            if(this->size() == 0){
                throw "Queue empty";
            }
            T firstValue = oldest.top();
            return firstValue;
        }
        
};

int main(){
    Queue<int, int> *queue = new Queue<int, int>();
    try{
        queue->push(1);
        cout<<queue->peek()<<endl;
        cout<<queue->pop()<<endl;
        queue->pop();
    }catch(const char* error){
        cout<<error<<endl;
    }
    return 0;
}