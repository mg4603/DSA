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
    int getHeight(TreeNode *root)
    {
        if(!root)
        {
            return 0;
        }
        int lHeight = getHeight(root->left);
        int rHeight = getHeight(root->right);
        if(lHeight == -1 || rHeight == -1)
        {
            return -1;
        }
        if(std::abs(lHeight - rHeight) > 1)
        {
            return -1;
        }
        return std::max(lHeight, rHeight) + 1;
    }
public:
    bool isBalanced(TreeNode* root) {
        int height = getHeight(root);
        if(height != -1)
        {
            return true;
        }
        return false;
    }
};

int main()
{
    Solution sol;
    {
        TreeNode *root = new TreeNode(3);
        root->left = new TreeNode(9);
        root->right = new TreeNode(20);

        root->right->left = new TreeNode(15);
        root->right->right = new TreeNode(7);
       
        assert(sol.isBalanced(root) == true);
    }
    {
        TreeNode *root = new TreeNode(1);
        root->left = new TreeNode(2);
        root->right = new TreeNode(2);

        root->left->left = new TreeNode(3);
        root->left->right = new TreeNode(3);

        root->left->left->left = new TreeNode(4);
        root->left->left->right = new TreeNode(4);

        assert(sol.isBalanced(root) == false);
    }
    {
        TreeNode *root = nullptr;

        assert(sol.isBalanced(root) == true);
    }
    return 0;
}