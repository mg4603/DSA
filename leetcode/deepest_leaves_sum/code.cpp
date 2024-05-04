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
    int getMaxDepth(TreeNode *root)
    {
        if(!root)return 0;
        int l = getMaxDepth(root->left);
        int r = getMaxDepth(root->right);
        return 1 + std::max(l, r);
    }
    void helper(TreeNode *root, int currDepth, 
                int maxDepth, int &res) {
        if(!root)return;
        if(currDepth == maxDepth)
        {
            res += root->val;
        }
        helper(root->left, currDepth + 1, maxDepth, res);
        helper(root->right, currDepth + 1, maxDepth, res);
    }
public:
    int deepestLeavesSum(TreeNode* root) {
        std::ios::sync_with_stdio(0);
        int maxDepth = getMaxDepth(root);
        int res = 0;
        helper(root, 1, maxDepth, res);
        return res;
    }
};

int main()
{
    return 0;
}