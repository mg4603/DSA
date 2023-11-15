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
    void helper(TreeNode *root, std::vector<std::vector<int>> &res, 
                int targetSum, std::vector<int> temp)
    {
        if(root == nullptr)
        {
            return;
        }

        targetSum -= root->val;
        temp.push_back(root->val);

        if(!root->left && !root->right)
        {
            if(targetSum == 0)
            {
                res.push_back(temp);
            }
            return;

        }

        helper(root->left, res, targetSum, temp);
        helper(root->right, res, targetSum, temp);
    }
public:
    std::vector<std::vector<int>> pathSum(TreeNode* root, int targetSum) 
    {
        std::vector<std::vector<int>> res;
        helper(root, res, targetSum, {});
        return res;    
    }
};

int main()
{
    Solution sol;
    {
        TreeNode *root = new TreeNode(5);

        root->left = new TreeNode(4);
        root->right = new TreeNode(8);

        root->right->left = new TreeNode(13);
        root->right->right = new TreeNode(4);

        root->right->right->left = new TreeNode(5);
        root->right->right->right = new TreeNode(1);

        root->left->left = new TreeNode(11);

        root->left->left->left = new TreeNode(7);
        root->left->left->right = new TreeNode(2);

        int target_sum = 22;

        std::vector<std::vector<int>> res = {{5,4,11,2},{5,8,4,5}};
        assert(sol.pathSum(root, target_sum) == res);
    }
    {
        TreeNode *root = new TreeNode(5);

        root->left = new TreeNode(4);
        root->right = new TreeNode(8);

        root->right->left = new TreeNode(13);
        root->right->right = new TreeNode(4);

        root->right->right->left = new TreeNode(5);
        root->right->right->right = new TreeNode(1);

        root->left->left = new TreeNode(11);

        root->left->left->left = new TreeNode(7);
        root->left->left->right = new TreeNode(2);

        int target_sum = 22;

        std::vector<std::vector<int>> res = {{5,4,11,2},{5,8,4,5}};
        assert(sol.pathSum(root, target_sum) == res);
    }
    {
        TreeNode *root = new TreeNode(1);

        root->left = new TreeNode(2);
        root->right = new TreeNode(3);

        int target_sum = 5;

        std::vector<std::vector<int>> res = {};
        assert(sol.pathSum(root, target_sum) == res);
    }
    {
        TreeNode *root = new TreeNode(1);

        root->left = new TreeNode(2);

        int target_sum = 0;

        std::vector<std::vector<int>> res = {};
        assert(sol.pathSum(root, target_sum) == res);
    }
    return 0;
}