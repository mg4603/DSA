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
    void inorderTraversal(TreeNode* root, std::vector<int> &res)
    {
        if(root == nullptr)
        {
            return;
        }
        inorderTraversal(root->left, res);
        res.push_back(root->val);
        inorderTraversal(root->right, res);
    }
public:
    std::vector<int> inorderTraversal(TreeNode* root) {
        std::vector<int> res;
        inorderTraversal(root, res);
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
        assert(sol.inorderTraversal(root) == std::vector<int>({1, 3, 2}));
    }
    {
        TreeNode *root = nullptr;
        std::vector<int> res;
        assert(sol.inorderTraversal(root) == res);
    }
    {
        TreeNode *root = new TreeNode(1);
        assert(sol.inorderTraversal(root) == std::vector<int>({1}));
    }
    return 0;
}