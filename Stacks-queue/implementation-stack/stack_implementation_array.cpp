#include<bits/stdc++.h>
using namespace std;

template <typename T>
class Stack{
    int top;
    vector<T> stack;

    public:
        Stack(){ top = -1; }  
        bool isEmpty();  
        bool push(T x);
        T pop();
        T peek();
        

};

template <typename T>
bool Stack<T>::push(T x){
    
    this->stack.push_back(x);
    this->top++;
    return true;
}

template <typename T>
T Stack<T>::pop(){
    if(this->isEmpty()){
        cout<<"Stack Underflow";
        return 0;
    }
    T temp = this->stack[this->top--];
    this->stack.pop_back();
    return temp;
}

template <typename T>
T Stack<T>::peek(){
    if(this->isEmpty())
    {
        cout<<"Stack is empty";
        return 0;
    }
    return this->stack[this->top];
}

template <typename T>
bool Stack<T>::isEmpty(){
    return (this->top < 0);
}

int main(){
    class Stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout<<s.pop()<<" Popped from stack \n";

    cout<<"Top element after popping from stack: "<<s.peek()<<"\n";

    cout<<"Elements present in stack : ";
    while(!s.isEmpty()){
        cout<<s.peek()<<" ";
        s.pop();
    }
    return 0;
}