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
public:
    int sumNumbers(TreeNode* root, int res = 0) 
    {
        if(root == nullptr)
        {
            return 0;
        }    
        res += root->val;

        if(root->left == nullptr && root->right == nullptr)
        {
            return res;
        }
        
        int left = sumNumbers(root->left, res * 10);
        int right = sumNumbers(root->right, res * 10);

        return left + right;
    }
};

int main()
{
    Solution sol;
    {
        TreeNode *root = new TreeNode(1);
        
        root->left = new TreeNode(2);
        root->right = new TreeNode(3);

        int res = 25;
        assert(sol.sumNumbers(root) == res);
    }
    {
        TreeNode *root = new TreeNode(4);
        
        root->left = new TreeNode(9);
        root->right = new TreeNode(0);

        root->left->left = new TreeNode(5);
        root->left->right = new TreeNode(1);

        int res = 1026;
        assert(sol.sumNumbers(root) == res);
    }
    return 0;
}