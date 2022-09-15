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
        void setRoot(TreeNode* root){
            this->root = root;
        }
        void insert(Q value){
            TreeNode* newNode = new TreeNode(value);
            if(root == nullptr){
                this->setRoot(newNode);
                return;
            }
            TreeNode *ptr = this->getRoot();
            while(ptr != nullptr){
                if(ptr->getValue() < value){
                    ptr = ptr->getRight();
                }else{
                    ptr = ptr->getLeft();
                }
            }
            ptr = newNode;
        }
};

int main(){
    Tree<int, int> *tree = new Tree<int, int>();
    tree->insert(1);
    return 0;
}