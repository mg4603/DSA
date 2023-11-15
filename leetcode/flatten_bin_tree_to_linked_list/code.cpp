#include <iostream>
#include <assert.h>

#include <stack>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void flatten(TreeNode* root) 
    {
        if(!root)
        {
            return;
        }
        std::stack<TreeNode*> st;

        while(true)
        {
            if(root->right)
            {
                st.push(root->right);
            }
            if(root->left == nullptr)
            {
                if(st.empty())
                {
                    break;
                }
                root->right = st.top();
                st.pop();
            }
            else
            {
                root->right = root->left;
                root->left = nullptr;;
            }
            root = root->right;
        }
    }
};

int main()
{
    return 0;
}