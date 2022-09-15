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
        };
    
        TreeNode* root;
    public:
        Tree():root(nullptr){}
};

int main(){
    return 0;
}