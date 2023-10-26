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
    bool checkTree(TreeNode* root) {
        return root->val == root->left->val + root->right->val;
    }
};

int main()
{
    Solution sol;
    {
        TreeNode *root = new TreeNode(10);
        root->left = new TreeNode(4);
        root->right = new TreeNode(6);

        bool res = 1;
        assert(sol.checkTree(root) == res);
    }
    {
        TreeNode *root = new TreeNode(5);
        root->left = new TreeNode(3);
        root->right = new TreeNode(1);

        bool res = 0;
        assert(sol.checkTree(root) == res);
    }
    return 0;
}