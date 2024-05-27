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


auto fast = []() {
    std::ios::sync_with_stdio(0);
    return 1;
}();

class Solution {
    int deepest;
    TreeNode *res;
    int helper(TreeNode *root, int depth) {
        deepest = std::max(depth, deepest);
        if(!root)return depth;

        int left = helper(root->left, depth + 1);
        int right = helper(root->right, depth + 1);
        if(left == deepest && right == deepest) {
            res = root;
        }
        return std::max(left, right);
    }
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        helper(root, 0);
        return res;
    }
};

int main()
{
    return 0;
}