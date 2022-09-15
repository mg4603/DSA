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
    
    TreeNode* root;
    public:
        Tree():root(NULL){}
        TreeNode* getRoot(){
            return this->root;
        }
        void setRoot(TreeNode* root){
            if(this->root == nullptr){
                this->root = root;
            }else{
                free(this->root);
                this->root = root;
            }
        }

        void inorder(){
            inorder(this->root);
        }

        bool isBalanced(){
            return isBalanced(this->root);
        }
        
        void insert( Q value){
        TreeNode* newNode = new TreeNode(value);
        if(root == nullptr){
            root = newNode;
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

        if(prevPtr->getValue() < value){
            prevPtr->setRight(newNode);
        }else{
            prevPtr->setLeft(newNode);
        }
        
    }
        
};

int main(){
    Tree<int, int> *tree = new Tree<int, int>();
    tree->insert(2);
    tree->insert(3);
    tree->insert(1);
    // tree->inorder();
    cout<<tree->isBalanced();
    return 0;
}