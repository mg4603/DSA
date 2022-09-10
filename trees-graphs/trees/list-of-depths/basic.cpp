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
        Q getValue(){
            return this->value;
        }
        void setValue(Q value){
            this->value = value;
        }
        TreeNode<Q>* getLeft(){
            return this->left;
        }
        TreeNode<Q>* getRight(){
            return this->right;
        }
        void setLeft(TreeNode<Q>* left){
            this->left = left;
        }
        void setRight(TreeNode<Q>* right){
            this->right = right;
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

template <typename T, typename Q>
class LinkedList{
    ListNode<Q> *front;
    public:
        LinkedList(){
            front = nullptr;
        }
        Q getFront(){
            if(this->empty()){
                throw "List empty";
            }
            return this->front->getValue();
        }

        Q getBack(){
            if(this->empty()){
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
            if(this->empty()){
                front = newNode;   
                return;
            }
            newNode->setNext(front);
            front = newNode;
        }    
        void push_back(Q value){
            ListNode<Q>* newNode = new ListNode<Q>(value);
            if(this->empty()){
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
            if(this->empty()){
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
            if(this->empty()){
                throw "List Empty";
            }

            Q value = front->getValue();
            ListNode<Q>* nodeToDelete;
            if(front->getNext() == nullptr){
                nodeToDelete = front;
                front = nullptr;
            }else{
                ListNode<Q> *runner = front;
                while(runner->getNext() != nullptr ){
                    runner = runner->getNext();
                }
                nodeToDelete = runner;
            }

            free(nodeToDelete);
            return value;

        }
        ListNode<Q>* begin(){
            if(this->empty()){
                throw "List Empty";
            }
            return this->front;
        }

        bool empty(){
            if(front == nullptr){
                return true;
            }
            return false;
        }

        T size(){
            if(this->empty()){
                return 0;
            }
            ListNode<Q> *runner = front;
            T cnt(1);
            while(runner->getNext() != nullptr){
                runner = runner->getNext();
                cnt++;
            }
            return cnt;
        }

        void insert(T pos, Q value){
            if(pos > this->size()){
                cout<<"Pos greater than size of list.\n Appending to end of list";
                this->push_back(value);
            }
            ListNode<Q> *runner = this->front;
            while(pos--){
                runner = runner->getNext();
            }
            ListNode<Q> *newNode = new ListNode<Q>(value);
            newNode->setNext(runner->getNext());
            runner->setNext(newNode);
        }
};

template <typename Q>
class Tree{
    
    TreeNode<Q> *root;

    TreeNode<Q>* getRoot(){
        return this->root;
    }
    void setRoot(TreeNode<Q> *root){
        this->root = root;
    }
    
    public:
        Tree(){}

        void insert(Q value){
            TreeNode<Q> *newNode = new TreeNode<Q>(value);
            if(root == nullptr){
                this->setRoot(newNode);
                return;
            }
            TreeNode<Q> *ptr = root;
            while(ptr != null){
                if(ptr->getValue() < value){
                    ptr = ptr->getRight();
                }else{
                    ptr = ptr->getLeft();
                }
            }
            if(value > ptr->getValue()){
                ptr->setRight(newNode);
            }else{
                ptr->setLeft(newNode);
            }
        }
        
};


int main(){

    return 0;
}