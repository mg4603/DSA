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
    int res;
    void helper(TreeNode *root, int &k)
    {
        if(!root)
        {
            return;
        }
        helper(root->left, k);
        k--;
        if(k == 0)
        {
            res = root->val;
            return;
        }
        helper(root->right, k);
    }

public:
    Solution(): res(0){}
    int kthSmallest(TreeNode* root, int k) 
    {
        helper(root, k);
        return res;
    }
};

int main()
{
    return 0;
}