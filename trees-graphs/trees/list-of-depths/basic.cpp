#include<iostream>
#include<vector>
using namespace std;


template <typename T, typename Q>
class LinkedList{
    struct ListNode{
    private:
        Q value;
        ListNode* next;
    public:
        ListNode(Q value){
            this->value = value;
        }
        void setValue(Q value){
            this->value = value;
        }
        void setNext(ListNode* next){
            this->next = next;
        }
        Q getValue(){
            return this->value;
        }
        ListNode* getNext(){
            return this->next;
        }
};
    ListNode *front;
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
            ListNode* runner = front;
            while(runner->getNext() != nullptr){
                runner = runner->getNext();
            }
            return runner->getValue();
        }

        void push_front(Q value){
            ListNode* newNode = new ListNode(value);
            if(this->empty()){
                front = newNode;   
                return;
            }
            newNode->setNext(front);
            front = newNode;
        }    
        void push_back(Q value){
            ListNode* newNode = new ListNode(value);
            if(this->empty()){
                front = newNode;
                return;
            }
            ListNode* runner = front;
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
            ListNode* nodeToDelete = front;
            
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
            ListNode* nodeToDelete;
            if(front->getNext() == nullptr){
                nodeToDelete = front;
                front = nullptr;
            }else{
                ListNode *runner = front;
                while(runner->getNext() != nullptr ){
                    runner = runner->getNext();
                }
                nodeToDelete = runner;
            }

            free(nodeToDelete);
            return value;

        }
        ListNode* begin(){
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
            ListNode *runner = front;
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
            ListNode *runner = this->front;
            while(pos--){
                runner = runner->getNext();
            }
            ListNode *newNode = new ListNode(value);
            newNode->setNext(runner->getNext());
            runner->setNext(newNode);
        }

        void print(){
            if(front == nullptr){
                throw "List empty";
            }
            ListNode* runner = front;
            while(runner != nullptr){
                cout<<runner->getValue()<<endl;
                runner = runner->getNext();
            }
        }
};

template <typename T, typename Q>
class Tree{
    struct TreeNode{
        private:
            Q value;
            TreeNode *left, *right;
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
            TreeNode* getLeft(){
                return this->left;
            }
            TreeNode* getRight(){
                return this->right;
            }
            void setLeft(TreeNode* left){
                this->left = left;
            }
            void setRight(TreeNode* right){
                this->right = right;
            }
    };

    TreeNode *root;

    TreeNode* getRoot(){
        if(this->root == nullptr){
            throw "Tree is empty";
        }
        return this->root;
    }
    void setRoot(TreeNode *root){
        this->root = root;
    }
    
    void createLevelLinkedLists(TreeNode *ptr, vector<LinkedList<T, Q>*> lists ,T level){
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
            list->push_back(ptr->getValue());
            createLevelLinkedLists(ptr->getLeft(), lists, level + 1);
            createLevelLinkedLists(ptr->getRight(), lists, level + 1);
    }

    public:
        Tree(){}

        void insert(Q value){
            TreeNode *newNode = new TreeNode(value);
            if(root == nullptr){
                this->setRoot(newNode);
                return;
            }
            TreeNode *ptr = root;
            TreeNode *prevPtr;
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

        TreeNode* search(TreeNode* ptr, Q key){
            if(ptr == NULL || ptr->getValue() == key){
                return ptr;
            }
            if(ptr->getValue() < key){
                return search(ptr->getRight(), key);
            }else{
                return search(ptr->getLeft(), key);
            }   
            
        }
        
        TreeNode* search(Q key){
            return search(this->root, key);
        }

        
        
        void createLevelLinkedLists(vector<LinkedList<T, Q>*> lists){
            this->createLevelLinkedLists(this->root, lists, 0);
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
    vector<LinkedList<int, int>*> lists;
    tree->createLevelLinkedLists(lists);
    // lists[0]->print();
    
    return 0;
}