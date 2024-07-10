#include <iostream>
#include <assert.h>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : 
        val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : 
        val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : 
        val(x), left(left), right(right) {}
};

class Solution {
    void helper(TreeNode *root, int &cumulativeSum)
    {
        if(!root)return;

        helper(root->right, cumulativeSum);
        root->val += cumulativeSum;
        cumulativeSum = root->val;
        helper(root->left, cumulativeSum);

    }
public:
    TreeNode* bstToGst(TreeNode* root) {
        int cumulativeSum = 0;
        helper(root, cumulativeSum);
        return root;
    }
};

int main()
{
    return 0;
}