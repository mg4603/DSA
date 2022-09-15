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
        };
    
        TreeNode* root;
    public:
        Tree():root(nullptr){}
};

int main(){
    return 0;
}