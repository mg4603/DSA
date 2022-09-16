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
                    this->left = left;
                }
                void setRight(TreeNode* right){
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
            this->root = root;
        }
        TreeNode* getRoot(){
            return this->root;
        }
        


};

int main(){
    return 0;
}