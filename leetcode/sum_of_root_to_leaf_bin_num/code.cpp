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
    int total_sum;
    void helper(TreeNode *root, int sum)
    {
        if(root != nullptr)
        {
            if(root->left == nullptr && root->right == nullptr)
            {
                total_sum += 2 * sum + root->val;
                return;
            }
    
            sum = sum * 2 + root->val;
            helper(root->left, sum);
            helper(root->right, sum);
    
        }
    }
public:
    int sumRootToLeaf(TreeNode* root) {
        total_sum = 0;
        helper(root, 0);
        return total_sum;
    }
};

int main()
{
    Solution sol;
    {
        TreeNode *root = new TreeNode(0);
        assert(sol.sumRootToLeaf(root) == 0);
    }
    {
        TreeNode *root = new TreeNode(1);
        root->left = new TreeNode(0);
        root->right = new TreeNode(1);

        root->left->left = new TreeNode(0);
        root->left->right = new TreeNode(1);

        root->right->left = new TreeNode(0);
        root->right->right = new TreeNode(1);

        assert(sol.sumRootToLeaf(root) == 22);
    }
    return 0;
}