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

template <typename T, typename Q>
class Tree{
    
    TreeNode<Q> *root;

    TreeNode<Q>* getRoot(){
        if(this->root == nullptr){
            throw "Tree is empty"
        }
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
            TreeNode<Q> *prevPtr;
            while(ptr != nullptr){
                if(ptr->getValue() < value){
                    prevPtr = ptr;
                    ptr = ptr->getRight();
                }else{
                    prevPtr = ptr;
                    ptr = ptr->getLeft();
                }
            }
            if(value > prevPtr->getValue()){
                prevPtr->setRight(newNode);
            }else{
                prevPtr->setLeft(newNode);
            }
        }

        TreeNode<Q>* search(TreeNode<Q>* ptr, Q key){
            if(ptr == NULL || ptr->getValue() == key){
                return ptr;
            }
            if(ptr->getValue() < key){
                return search(ptr->getRight(), key);
            }else{
                return search(ptr->getLeft(), key);
            }   
            
        }
        
        TreeNode<Q>* search(Q key){
            return search(this->root, key);
        }

        void createLevelLinkedLists(TreeNode<Q> *ptr, vector<LinkedList<T, Q>*> lists ,T level){
            if(ptr == nullptr){
                return;
            }
            LinkedList<T, Q> *list;
            if(lists.size() == level){
                list = new LinkedList<T, Q>();
                lists.push_back(list);
            }else{
                list = lists.at(level);
            }
            list->push_back(root);
            createLevelLinkedLists(ptr->getLeft(), lists, level + 1);
            createLevelLinkedLists(ptr->getRight(), lists, level + 1);
        }
        
};


int main(){
    Tree<int, int> *tree = new Tree<int, int>();
    tree->insert(1);
    tree->insert(2);
    tree->insert(3);
    tree->insert(4);
    tree->insert(5);
    tree->insert(6);
    tree->insert(7);
    tree->insert(8);
    tree->insert(9);
    tree->insert(10);
    cout<<tree->search(5)->getRight()->getValue();
    return 0;
}