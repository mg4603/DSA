#include <iostream>
#include <assert.h>


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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root)
        {
            return false;
        }
        targetSum -= root->val;
        if(!root->left && !root->right)
        {
            if(targetSum == 0)
            {
                return true;
            }
        }
        return hasPathSum(root->left, targetSum) || hasPathSum(root->right, targetSum);
    }
};

int main()
{
    Solution sol;
    {
        TreeNode *root = nullptr;
        assert(sol.hasPathSum(root, 0) == false);
    }
    {
        TreeNode *root = new TreeNode(1);
        root->left = new TreeNode(2);
        root->right = new TreeNode(3);

        assert(sol.hasPathSum(root, 0) == false);
    }
    {
        TreeNode *root = new TreeNode(5);

        root->left = new TreeNode(4);
        root->right = new TreeNode(8);
        
        root->left->left = new TreeNode(11);
        root->left->left->left = new TreeNode(7);
        root->left->left->right = new TreeNode(2);

        root->right->left = new TreeNode(13);
        root->right->right = new TreeNode(4);
        
        root->right->right->right = new TreeNode(1);

        assert(sol.hasPathSum(root, 22) == true);
    }
    return 0;
}