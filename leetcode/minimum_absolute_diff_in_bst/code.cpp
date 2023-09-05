#include <iostream>
#include <assert.h>

#include <limits>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    void getMinimumDifference(TreeNode *root, int &previousVal, int &minDiff)
    {
        if(root == nullptr)
        {
            return;
        }
        getMinimumDifference(root->left, previousVal, minDiff);
        if(previousVal != -1)
        {
            minDiff = std::min(minDiff, std::abs(root->val - previousVal));
        }
        previousVal = root->val;
        getMinimumDifference(root->right, previousVal, minDiff);
    }
public:
    int getMinimumDifference(TreeNode* root) {
        int minDiff(std::numeric_limits<int>::max());
        int previousVal(-1);
        getMinimumDifference(root, previousVal, minDiff);
        return minDiff;
    }
};

int main()
{
    Solution sol;
    {
        TreeNode *root = new TreeNode(4);
        root->left = new TreeNode(2);
        root->right = new TreeNode(6);

        root->left->left = new TreeNode(1);
        root->left->right = new TreeNode(3);
        assert(sol.getMinimumDifference(root) == 1);
    }
    {
        TreeNode *root = new TreeNode(1);
        root->left = new TreeNode(0);
        root->right = new TreeNode(48);

        root->right->left = new TreeNode(12);
        root->right->right = new TreeNode(49);
        assert(sol.getMinimumDifference(root) == 1);
    }
    return 0;
}