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
    bool check_val(TreeNode *root, int val)
    {
        if(root == nullptr)
        {
            return true;
        }
        int left = check_val(root->left, val);
        int right = check_val(root->right, val);
        int current = (root->val == val);
        return left && right && current;
    }
public:
    bool isUnivalTree(TreeNode* root) {
        if(root == nullptr)
        {
            return false;
        }
        int val = root->val;
        return check_val(root, val);
    }
};

int main()
{
    Solution sol;
    {
        TreeNode *root = new TreeNode(1);
        root->left = new TreeNode(1);
        root->right = new TreeNode(1);

        root->left->left = new TreeNode(1);
        root->left->right = new TreeNode(1);

        root->right->right = new TreeNode(1);

        bool res = true;
        assert(sol.isUnivalTree(root) == res);
    }
    {
        TreeNode *root = new TreeNode(2);

        root->left = new TreeNode(2);
        root->right = new TreeNode(3);

        root->left->left = new TreeNode(5);
        root->left->right = new TreeNode(2);
        
        bool res = false;
        assert(sol.isUnivalTree(root) == res);
    }
    return 0;
}