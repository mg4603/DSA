#include<iostream>
#include<vector>

using namespace std;

template <typename T, typename Q>
class Tree{
    class TreeNode{
        Q value;
        TreeNode* left;
        TreeNode* right;
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
            void setLeft(TreeNode* left){
                this->left = left;
            }
            TreeNode* getRight(){
                return this->right;
            }
            void setRight(TreeNode* right){
                this->right = right;
            }
    };
    TreeNode* root;
    public:
        Tree():root(NULL){}
        TreeNode* getRoot(){
            return this->root;
        }
        TreeNode* setRoot(TreeNode* root){
            this->root = root;
        }
};

int main(){
    return 0;
}