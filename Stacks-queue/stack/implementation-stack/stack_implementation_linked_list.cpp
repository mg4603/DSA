#include<bits/stdc++.h>
using namespace std;

template <typename T>
class StackNode{
    T data;
    StackNode *next;
    public: 
        StackNode(T data){
            this->data = data;
            this->next = NULL;
        }
        void setNext(StackNode* next){
            this->next = next;
        }
        StackNode* getNext(){
            return this->next;
        }
        void setData(T data){
            this->data = data;
        }
        T getData(){
            return this->data;
        }
};

template <typename T>
class Stack{
    StackNode<T> *top;
    public:
        Stack();
        StackNode<T>* newNode(T data);
        bool isEmpty();
        bool push(T data);
        T pop();
        T peek();
};

template <typename T>
Stack<T>::Stack(){
    StackNode<T>* top = NULL;
}

template <typename T>
StackNode<T>* Stack<T>::newNode(T data){
    StackNode<T>* stackNode = new StackNode<T>(data);
    return stackNode;
}

template <typename T>
bool Stack<T>::isEmpty(){
    return !top;
}

template <typename T>
bool Stack<T>::push(T data){
    StackNode<T>* newStackNode = newNode(data);
    newStackNode->setNext(this->top);
    this->top = newStackNode;
    return this->top;
}

template <typename T>
T Stack<T>::pop(){
    if(this->isEmpty()){
        cout<<"Stack empty"<<endl;
        return static_cast<T>(0);
    }
    T data = this->top->getData();
    this->top = this->top->getNext();
    return data;
}

template <typename T>
T Stack<T>::peek(){
    return this->top->getData();
}

int main(){
    class Stack<int> s;
    cout<<s.isEmpty()<<endl;
    s.push(10);
    s.push(20);
    cout<<s.isEmpty()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    
    return 0;
}