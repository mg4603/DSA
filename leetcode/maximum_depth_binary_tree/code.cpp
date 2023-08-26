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
    int maxDepth(TreeNode* root) {
        if(root == nullptr)
        {
            return 0;
        }
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        return std::max(left, right) + 1;
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
        assert(sol.maxDepth(root) == 3);
    }
    {
        TreeNode *root = new TreeNode(1);
        root->right = new TreeNode(2);

        assert(sol.maxDepth(root) == 2);
    }
    return 0;
}