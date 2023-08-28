#include <iostream>
#include <assert.h>

#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    void postorderTraversal(TreeNode *root, std::vector<int> &res)
    {
        if(root == nullptr)
        {
            return;
        }
        postorderTraversal(root->left, res);
        postorderTraversal(root->right, res);
        res.push_back(root->val);
    }
public:
    std::vector<int> postorderTraversal(TreeNode* root) {
        std::vector<int> res;
        postorderTraversal(root, res);
        return res;
    }
};

int main()
{
    Solution sol;
    {
        TreeNode *root = nullptr;
        assert(sol.postorderTraversal(root) == std::vector<int>({}));
    }
    {
        TreeNode *root = new TreeNode(1);
        assert(sol.postorderTraversal(root) == std::vector<int>({1}));
    }
    {
        TreeNode *root = new TreeNode(1);
        root->right = new TreeNode(2);
        root->right->left = new TreeNode(3);
        assert(sol.postorderTraversal(root) == std::vector<int>({3, 2, 1}));
    }
    return 0;
}