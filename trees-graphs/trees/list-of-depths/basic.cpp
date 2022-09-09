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
    ListNode<Q> *front;
    public:
        LinkedList(){
            front = nullptr;
        }
        Q getFront(){
            if(front == nullptr){
                throw "List empty";
            }
            return this->front->getValue();
        }

        Q getBack(){
            if(front == nullptr){
                throw "List Empty";
            }
            ListNode<Q>* runner = front;
            while(runner->getNext() != nullptr){
                runner = runner->getNext();
            }
            return runner->getValue();
        }

        void push_front(Q value){
            ListNode<Q>* newNode = new ListNode<Q>(value);
            if(front == nullptr){
                front = newNode;   
                return;
            }
            newNode->setNext(front);
            front = newNode;
        }    
        void push_back(Q value){
            ListNode<Q>* newNode = new ListNode<Q>(value);
            if(front == nullptr){
                front = newNode;
                return;
            }
            ListNode<Q>* runner = front;
            while(runner != nullptr){
                runner =  runner->getNext();
            }
            runner = newNode;
        }

        Q pop_front(){
            if(front == nullptr){
                throw "List empty";
            }
            
            Q value = front->getValue();
            ListNode<Q>* nodeToDelete = front;
            
            if(front->getNext() == nullptr){    
                front = nullptr;
            }else{
                front = front->getNext();
            }

            free(nodeToDelete);
            return value;            
        }
        Q pop_back(){
            if(front == nullptr){
                throw "List Empty";
            }
            Q value = front->getValue();
            ListNode<Q>* nodeToDelete = front;
            if(front == back){
                front = nullptr;
                back = nullptr;
            }else{
                ba
            }


        }
};

int main(){

    return 0;
}