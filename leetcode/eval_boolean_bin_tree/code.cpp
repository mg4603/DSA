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
    bool evaluateTree(TreeNode* root) {
        if(root->left == nullptr && root->right == nullptr)
        {
            return root->val;
        }
        int left = evaluateTree(root->left);
        int right = evaluateTree(root->right);
        if(root->val == 2)
        {
            return left || right;
        }
        return left && right;
    }
};

int main()
{
    Solution sol;
    {
        TreeNode *root = new TreeNode(2);
        root->left = new TreeNode(1);
        root->right = new TreeNode(3);

        root->right->left = new TreeNode(0);
        root->right->right = new TreeNode(1);

        bool res = true;
        assert(sol.evaluateTree(root) == res);
    }
    {
        TreeNode *root = new TreeNode(0);

        bool res = false;
        assert(sol.evaluateTree(root) == res);
    }
    return 0;
}