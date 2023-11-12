#include <iostream>
#include <assert.h>

#include <vector>
#include <algorithm>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    void helper(TreeNode *root, 
                std::vector<std::vector<int>> &res, 
                int height)
    {
        if(root == nullptr)
        {
            return;
        }
        if(res.size() < height)
        {
            res.push_back({});
        }
        res[height - 1].push_back(root->val);

        helper(root->left, res, height + 1);
        helper(root->right, res, height + 1);
    }
public:
    std::vector<std::vector<int>> zigzagLevelOrder(TreeNode* root)
    {
        std::vector<std::vector<int>> res;
        helper(root, res, 1);
        for(int i = 1; i < res.size(); i += 2)
        {
            std::reverse(res[i].begin(), res[i].end());
        }
        return res;    
    }
};

int main()
{
    Solution sol;
    {
        TreeNode *root = new TreeNode(1);
        std::vector<std::vector<int>> res = {{1}};
        assert(sol.zigzagLevelOrder(root) == res);
    }
    {
        TreeNode *root = nullptr;
        std::vector<std::vector<int>> res = {};
        assert(sol.zigzagLevelOrder(root) == res);
    }
    {
        TreeNode *root = new TreeNode(3);

        root->left = new TreeNode(9);
        root->right = new TreeNode(20);

        root->right->left = new TreeNode(15);
        root->right->right = new TreeNode(7);

        std::vector<std::vector<int>> res = {{3}, {20, 9}, {15, 7}};
        assert(sol.zigzagLevelOrder(root) == res);
    }
    return 0;
}