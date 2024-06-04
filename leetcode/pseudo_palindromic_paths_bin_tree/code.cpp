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
    void solve(TreeNode *root, int flag, int &res) {
        if(!root)return;

        flag ^= (1 << root->val);
        if(!root->left && !root->right && 
            __builtin_popcount(flag) <= 1)res++;
        solve(root->left, flag, res);
        solve(root->right, flag, res);
    }
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        int res = 0;
        solve(root, 0, res);
        return res;
    }
};

int main()
{
    TreeNode *root = new TreeNode(2);
    root->left = new TreeNode(3);
    root->right = new TreeNode(1);

    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(1);

    root->right->right = new TreeNode(1);
    int res = 2;
    Solution sol;
    assert(sol.pseudoPalindromicPaths(root) == res);
    return 0;
}