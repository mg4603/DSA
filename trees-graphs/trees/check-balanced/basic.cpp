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
    void inorder(TreeNode* ptr){ 
        if(ptr != nullptr){
            inorder(ptr->getLeft());
            cout<<ptr->getValue()<<endl;
            inorder(ptr->getRight());
        }
    }
    T getHeight(TreeNode* ptr){
        // base case
        if(ptr == nullptr){
            return -1;
        }
        return max(getHeight(ptr->getRight()), getHeight(ptr->getLeft())) + 1;
    }

    bool isBalanced(TreeNode* ptr){
            if(ptr == nullptr){
                return true;
            }
            T heightDiff(getHeight(ptr->getLeft()) - getHeight(ptr->getRight()));
            if(abs(heightDiff) > 1){
                return false;
            }else{
                return isBalanced(ptr->getLeft()) && isBalanced(ptr->getRight());
            }
    }
    TreeNode* insert(TreeNode* ptr, Q value){
        TreeNode* newNode = new TreeNode(value);
        if(ptr == nullptr){
            ptr = newNode;
            return ptr;
        }
        
        if(ptr->getValue() < value){
            return insert(ptr->getRight(), value);
        }else{
            return insert(ptr->getLeft(), value);
        }
    }
    TreeNode* root;
    public:
        Tree():root(NULL){}
        TreeNode* getRoot(){
            return this->root;
        }
        void setRoot(TreeNode* root){
            this->root = root;
        }
     

        void inorder(){
            inorder(this->root);
        }

        bool isBalanced(){
            return isBalanced(this->root);
        }
        
        void insert(Q value){
            this->setRoot(insert(this->root, value));
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
    cout<<tree->getRoot()->getLeft();
    // tree->inorder();
    // cout<<tree->isBalanced();
    return 0;
}