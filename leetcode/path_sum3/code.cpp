#include <iostream>
#include <assert.h>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : 
            val(0), 
            left(nullptr), 
            right(nullptr) {}
    TreeNode(int x) : 
                val(x), 
                left(nullptr), 
                right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : 
                            val(x), left(left), 
                            right(right) {}
};

class Solution {
    int helper(TreeNode *root, long target)
    {
        if(!root)return 0;
        return helper(root->left, target - root->val) + 
                helper(root->right, target - root->val) + 
                (root->val == target ? 1 : 0);
    }
public:
    int pathSum(TreeNode* root, int targetSum) 
    {
        if(!root)return 0;
        return helper(root, targetSum) + 
                pathSum(root->left, targetSum) + 
                pathSum(root->right, targetSum);
    }
};

int main()
{
    return 0;
}