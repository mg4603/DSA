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
    int findTilt(TreeNode *root, int &sum)
    {
        if(root == nullptr)
        {
            return 0;
        }
        int left = findTilt(root->left, sum);
        int right = findTilt(root->right, sum);
        sum += std::abs(left - right);
        return left + right + root->val;
    }
public:
    int findTilt(TreeNode* root) {
        int sum(0);
        findTilt(root, sum);
        return sum;
    }
};

int main()
{
    Solution sol;
    {
        TreeNode *root = new TreeNode(1);
        root->left = new TreeNode(2);
        root->right = new TreeNode(3);
        assert(sol.findTilt(root) == 1);
    }
    {
        TreeNode *root = new TreeNode(4);
        root->left = new TreeNode(2);
        root->right = new TreeNode(9);

        root->left->left = new TreeNode(3);
        root->left->right = new TreeNode(5);

        root->right->right = new TreeNode(7);

        assert(sol.findTilt(root) == 15);
    }
    {
        TreeNode *root = new TreeNode(21);
        root->left = new TreeNode(7);
        root->right = new TreeNode(14);

        root->left->left = new TreeNode(1);
        root->left->right = new TreeNode(1);
        
        root->left->left->left = new TreeNode(3);
        root->left->left->right = new TreeNode(3);

        root->right->left = new TreeNode(2);
        root->right->right = new TreeNode(2);
        
        assert(sol.findTilt(root) == 9);
    }
    return 0;
}