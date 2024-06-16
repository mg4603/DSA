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
    void maxZigZag(TreeNode *root, bool isLeft, int curr, int &maxi) {
        if(!root)return;
        maxi = std::max(curr, maxi);
        if(isLeft) {
            maxZigZag(root->right, false, curr + 1, maxi);
            maxZigZag(root->left, true, 1, maxi);
        } else {
            maxZigZag(root->left, true, curr + 1, maxi);
            maxZigZag(root->right, false, 1, maxi);
        }
    }
public:
    int longestZigZag(TreeNode* root) {
        int res = 0;
        maxZigZag(root, true, 0, res);
        maxZigZag(root, false, 0, res);
        return res;
    }
};

int main()
{
    return 0;
}