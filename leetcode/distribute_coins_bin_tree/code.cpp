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
    int dfs(TreeNode *root, int &moves) {
        if(!root)return 0;

        int left = dfs(root->left, moves);
        int right = dfs(root->right, moves);

        moves += std::abs(left) + std::abs(right);
        return (root->val - 1) + left + right;
    }
public:
    int distributeCoins(TreeNode* root) {
        int moves = 0;
        dfs(root, moves);
        return moves;        
    }
};

int main()
{
    TreeNode * root = new TreeNode(3);
    root->left = new TreeNode(0);
    root->right = new TreeNode(0);

    Solution sol;
    assert(sol.distributeCoins(root) == 2);
    return 0;
}