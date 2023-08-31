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
    bool isLeaf(TreeNode *root)
    {
        if(root == nullptr)
        {
            return false;
        }

        if(root->left == nullptr && root->right == nullptr)
        {
            return true;
        }
        return false;
    }
    void sumOfLeftLeaves(TreeNode *root, int &sum)
    {
        if(root == nullptr)
        {
            return;
        }
        if(isLeaf(root->left))
        {
            sum += root->left->val;
        }
        sumOfLeftLeaves(root->left, sum);
        sumOfLeftLeaves(root->right, sum);
    }
public:
    int sumOfLeftLeaves(TreeNode* root) {
        int sum(0);
        sumOfLeftLeaves(root, sum);
        return sum;
    }
};

int main()
{
    Solution sol;
    {
        TreeNode *root = new TreeNode(1);
        assert(sol.sumOfLeftLeaves(root) == 0);
    }
    {
        TreeNode *root = new TreeNode(3);
        root->left = new TreeNode(9);
        root->right = new TreeNode(20);

        root->right->left = new TreeNode(15);
        root->right->right = new TreeNode(7);
        assert(sol.sumOfLeftLeaves(root) == 24);
    }
    return 0;
}