#include<iostream>
using namespace std;

template <typename T>
struct Node{
    T data;
    Node<T>* next;
    Node(T data);
};

template <typename T>
class Queue{
    Node<T>* front;
    public:
        Queue();
        bool add(Node<T>* item);
        Node<T>* remove();
        T peek();
        bool isEmpty();
};

template <typename T>
Node<T>::Node(T data){
    this->data = data;
}

template <typename T>
Queue<T>::Queue(){}

template <typename T>
bool Queue<T>::add(Node<T>* item){
    if(this->front == nullptr){
        this->front = item;
        return true;
    }
    
    Node<T> *n = this->front;
    while(n->next != nullptr){
        n = n->next;
    }
    n->next = item;
    return true;
}

template <typename T>
Node<T>* Queue<T>::remove(){
    if(this->front == nullptr){
        return nullptr;
    }

    Node<T> *n = this->front;
    this->front = n->next;
    return n;
}

template <typename T>
T Queue<T>::peek(){
    Node<T> *n = this->front;
    return n->data;
}

template <typename T>
bool Queue<T>::isEmpty(){
    if(this->front == nullptr){
        return true;
    }
    return false;
}
int main(){
    Queue<int> *q = new Queue<int>();
    q->add(new Node<int>(5));
    cout<<q->peek()<<endl;
    cout<<"Is Empty?"<<(q->isEmpty()?"true":"false")<<endl;
    q->add(new Node<int>(1));
    Node<int> * n = q->remove();
    cout<<n->data<<endl;
    cout<<q->peek()<<endl;
    return 0;
}