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
    void preorderTraversal(TreeNode *root, std::vector<int> &res)
    {
        if(root == nullptr)
        {
            return;
        }
        res.push_back(root->val);
        preorderTraversal(root->left, res);
        preorderTraversal(root->right, res);
    }
public:
    std::vector<int> preorderTraversal(TreeNode* root) {
        std::vector<int> res;
        preorderTraversal(root, res);
        return res;
    }
};

int main()
{
    Solution sol;
    {
        TreeNode *root = new TreeNode(1);
        root->right = new TreeNode(2);
        root->right->left = new TreeNode(3);
        assert(sol.preorderTraversal(root) == std::vector<int>({1, 2, 3}));
    }
    {
        TreeNode *root = nullptr;
        assert(sol.preorderTraversal(root) == std::vector<int>({}));
    }
    {
        TreeNode *root = new TreeNode(1);
        assert(sol.preorderTraversal(root) == std::vector<int>({1}));
    }
    return 0;
}