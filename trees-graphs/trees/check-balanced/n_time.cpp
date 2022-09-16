#include<iostream>
#include<limits>
#define INT_MIN numeric_limits<int>::min()

using namespace std;

template <typename T, typename Q>
class Tree{
    private:        
        class TreeNode{
            private:
                Q value;
                TreeNode* left;
                TreeNode* right;
            public:
                TreeNode(Q value){
                    this->value = value;
                }
                void setValue(Q value){
                    this->value = value;
                }
                void setLeft(TreeNode* left){
                    if(this->getLeft() != nullptr){
                        free(this->getLeft());
                    }
                    this->left = left;
                }
                void setRight(TreeNode* right){
                    if(this->getRight() != nullptr){
                        free(this->getRight());
                    }
                    this->right = right;
                }
                Q getValue(){
                    return this->value;
                }
                TreeNode* getLeft(){
                    return this->left;
                }
                TreeNode* getRight(){
                    return this->right;
                }
        };
        void inorderPrint(TreeNode* root){
            if(root != nullptr){
                inorderPrint(root->getLeft());
                cout<<root->getValue()<<" ";
                inorderPrint(root->getRight());
            }
        }
        TreeNode* root;
    public:
        Tree():root(nullptr){}

        void setRoot(TreeNode* root){
            if(this->getRoot() != nullptr){
                free(this->getRoot());
            }
            this->root = root;
        }

        TreeNode* getRoot(){
            return this->root;
        }
        
        void inorderPrint(){
            inorderPrint(this->getRoot());
        }

        void insert(Q value){
            TreeNode* newNode = new TreeNode(value);
            if(this->getRoot() == nullptr){
                this->setRoot(newNode);
                return;
            }
            TreeNode *ptr = this->getRoot();
            TreeNode *prevPtr;
            while(ptr != nullptr){
                prevPtr = ptr;
                if(ptr->getValue() < value){
                    ptr = ptr->getRight();
                }else{
                    ptr = ptr->getLeft();
                }
            }

            if(prevPtr->getValue() < value){
                prevPtr->setRight(newNode);
            }else{
                prevPtr->setLeft(newNode);
            }
        }
};

int main(){
    return 0;
}