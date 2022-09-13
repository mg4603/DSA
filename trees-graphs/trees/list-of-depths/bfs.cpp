#include<vector>
#include<iostream>
using namespace std;

template <typename T, typename Q>
class LinkedList{
    struct ListNode{
        private:
            Q value;
            ListNode *next, *prev;
        public:
            ListNode(Q value){
                this->value = value;
            }
            Q getValue(){
                return this->value;
            }
            void setValue(Q value){
                this->value = value;
            }
            void setNext(ListNode* next){
                this->next = next;
            }
            ListNode* getNext(){
                return this->next;
            }
            void setPrev(ListNode* prev){
                this->prev = prev;
            }
            ListNode* getPrev(){
                return this->prev
            } 
    };
    ListNode *start, *end;
    public:
        LinkedList(){
            start = nullptr;
            end = nullptr;
        }
        Q front(){
            if(start == nullptr){
                throw "List Empty";
            }
            return start->getValue()
        }
        Q back(){
            if(end == nullptr){
                throw "List Empty";
            }
            return end->getValue();
        }
        void push_front(Q value){
            ListNode* newNode = new ListNode(value);
            if(start == nullptr && end == nullptr){
                start = newNode;
                end = newNode;
                return;
            }
            
            newNode->setNext(start);
            start->setPrev(newNode);
            if(start->getNext() == nullptr){
                end->setPrev(newNode);
            }
            start = newNode;
        }

        void push_back(Q value){
            ListNode *newNode = new ListNode(value);
            if(start == nullptr && end == nullptr){
                start = newNode;
                end = newNode;
            }
            if(start->getNext() == nullptr){
                start->setNext(newNode);
            }
            end->setNext(newNode);
            newNode->setPrev(end);
            
            end = newNode;
        }
        
        void pop_front(){
            if(start == nullptr && end == nullptr){
                throw "List Empty";
            }
            if(start->getNext() == nullptr){
                start = nullptr;
                end = nullptr;
            }
            ListNode* nodeToDelete = start;
            start = start->getNext();
            start->setPrev(nullptr);
            free(nodeToDelete);
        }

        void pop_back(){
            if(start == nullptr && end == nullptr){
                throw "List Empty";
            }
            if(end->getPrev() == nullptr){
                start = nullptr;
                end = nullptr;
            }
            ListNode* nodeToDelete = end;
            end = end->getPrev();
            free(nodeToDelete);
        }
        
        bool empty(){
            if(start == nullptr && end == nullptr){
                return true;
            }
            return false;
        }

        T size(){
            if(this->empty()){
                return 0;
            }
            ListNode* runner = start;
            T count(0);
            while(runner != nullptr){
                count++;
                runner = runner->getNext();
            }
            return count;
        }
};

template<typename T, typename Q>
class Tree{
    private:
        struct TreeNode{
            private:
                Q value;
                TreeNode *left;
                TreeNode *right;
            public:
                TreeNode(Q value){
                    this->value = value;
                }
                void setValue(Q value){
                    this->value = value;
                }

                Q getValue(){
                    return this->value;
                }

                void setLeft(TreeNode* left){
                    this->left = left;
                }

                TreeNode* getLeft(){
                    return this->left;
                }

                void setRight(TreeNode* right){
                    this->right = right;
                }

                TreeNode* getRight(){
                    return this->right;
                }
        };
        

        TreeNode* search(TreeNode* ptr, Q key){
            if(ptr == nullptr || ptr->getValue() == key){
                return ptr;
            }
            if(ptr->getValue() < key){
                return search(ptr->getLeft(), key);
            }
            return search(ptr->getRight(), key);
        }


        TreeNode* root;


        void setRoot(Q value){
            TreeNode* root = new TreeNode(value);
            if(this->root == nullptr){
                this->root = root;
            }else{
                free(this->root);
                this->root = root;
            }
        }

        TreeNode* getRoot(){
            return this->root;
        }
    public:
        Tree():root(NULL){}
        TreeNode* search(Q key){
            return search(this->root, key);
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
    lists[0]->print();
    
    return 0;
}