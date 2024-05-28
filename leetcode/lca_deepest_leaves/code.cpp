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
    TreeNode *res;
    int maxDepth(TreeNode *root) {
        if(!root)return 0;
        return 1 + std::max(maxDepth(root->left), 
                        maxDepth(root->right));
    }

    bool helper(TreeNode *root, int depth) {
        if(depth == 0)return true;
        if(!root)return false;
        int left = helper(root->left, depth - 1);
        int right = helper(root->right, depth - 1);
        if(left && right) {
            res = root;
        }
        return left || right;
    }
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        helper(root, maxDepth(root));
        return res;
    }
};

int main()
{
    return 0;
}