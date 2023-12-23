#include <iostream>
#include <assert.h>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : 
        val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : 
        val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : 
        val(x), left(left), right(right) {}

};

class Solution {
    void dfs(TreeNode *root, int val, int depth)
    {
        if(!root)
        {
            return;
        }

        if(depth == 0)
        {
            TreeNode *left = root->left;
            TreeNode *right = root->right;
            root->left = new TreeNode(val);
            root->right = new TreeNode(val);
            root->left->left = left;
            root->right->right = right;
            return;
        }

        dfs(root->left, val, depth-1);
        dfs(root->right, val, depth-1);

    }
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) 
    {
        if(!root || depth == 1)
        {
            TreeNode *left = root;
            root = new TreeNode(val);
            root->left = left;
        }

        depth -= 2;
        dfs(root, val, depth);
        return root;    
    }
};

int main()
{
    return 0;
}