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


int main(){

    return 0;
}