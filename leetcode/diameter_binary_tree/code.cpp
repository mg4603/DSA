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
    std::pair<int, int> diameterHeight(TreeNode *root)
    {
        if(root == nullptr)
        {
            return std::make_pair(0, 0);
        }
        std::pair<int, int> left = diameterHeight(root->left);
        std::pair<int, int> right = diameterHeight(root->right);

        int lh = left.first;
        int ld = left.second;
        int rh = right.first;
        int rd = right.second;

        int height = 1 + std::max(lh, rh);
        int diameter = std::max(lh + rh, std::max(ld, rd));
        return std::make_pair(height, diameter);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        return diameterHeight(root).second;
    }
};

int main()
{
    Solution sol;
    {
        TreeNode *root = new TreeNode(1);
        root->right = new TreeNode(2);
        assert(sol.diameterOfBinaryTree(root) == 1);
    }
    {
        TreeNode *root = new TreeNode(1);
        root->left = new TreeNode(2);
        root->right = new TreeNode(3);

        root->left->left = new TreeNode(4);
        root->left->right = new TreeNode(5);
        
        assert(sol.diameterOfBinaryTree(root) == 3);
    }
    return 0;
}