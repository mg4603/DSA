#include<iostream>
#include<vector>
using namespace std;

template <typename Q>
struct TreeNode{
    private:
        Q value;
        TreeNode<Q> *left, *right;
    public:
        TreeNode(Q value){
            this->value = value;
        }
};

template <typename Q>
struct ListNode{
    private:
        Q value;
        ListNode<Q>* next;
    public:
        ListNode(Q value){
            this->value = value;
        }
        void setValue(Q value){
            this->value = value;
        }
        void setNext(ListNode<Q>* next){
            this->next = next;
        }
        Q getValue(){
            return this->value;
        }
        ListNode<Q>* getNext(){
            return this->next;
        }
};

template <typename Q>
class LinkedList{
    ListNode<Q>* front,*back;
    public:
        LinkedList(){
            front = nullptr;
        }
        Node<Q>* front(){
            if(front == nullptr){
                throw "List empty";
            }
            return this->front;
        }
        void push_front(Q value){
            ListNode<Q>* newNode = new ListNode<Q>(value);
            if(front == nullptr){
                front = newNode;   
                back = newNode;
                return;
            }
            newNode->setNext(front);
            front = newNode;
        }    
        void push_back(Q value){
            ListNode<Q>* newNode = new ListNode<Q>(value);
            if(front == nullptr){
                front = newNode;
                back = newNode;
                return;
            }
            back->setNext(newNode);
            back = back->getNext();
        }
        
};

int main(){

    return 0;
}