#include <iostream>
#include <assert.h>

#include <array>

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
    void solve(TreeNode *root, int &res, std::array<int, 2> min_max) {
        if(!root)return;

        int temp = std::abs(min_max[0] - root->val);
        res = std::max(res, temp);
        temp = std::abs(min_max[1] - root->val);
        res = std::max(res, temp);

        min_max[0] = std::min(min_max[0], root->val);
        min_max[1] = std::max(min_max[1], root->val);
        solve(root->left, res, min_max);
        solve(root->right, res, min_max);
    }
public:
    int maxAncestorDiff(TreeNode* root) {
        int res = 0L;
        std::array<int, 2> min_max{root->val, root->val};
        solve(root, res, min_max);
        return res;
    }
};

int main()
{
    return 0;
}