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
    int solve(TreeNode *root, int parent = 1, int grand = 1)
    {
        if(!root)return 0;

        return solve(root->left, root->val, parent) + 
            solve(root->right, root->val, parent) + 
            (grand % 2 ? 0 : root->val);
    }
public:
    int sumEvenGrandparent(TreeNode* root) {
        std::ios::sync_with_stdio(0);
        return solve(root);   
    }
};

int main()
{
    return 0;
}