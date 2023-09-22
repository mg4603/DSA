#include <iostream>
#include <assert.h>

#include <vector>
#include <limits>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    void inorder(TreeNode *root, std::vector<int> &vals)
    {
        if(root == nullptr)
        {
            return;
        }
        inorder(root->left, vals);
        vals.push_back(root->val);
        inorder(root->right, vals);
    }
public:
    int minDiffInBST(TreeNode* root) {
        std::vector<int> vals;
        inorder(root, vals);
        int min_diff(std::numeric_limits<int>::max());
        for(int i(1); i < vals.size(); i++)
        {
            min_diff = std::min(min_diff, vals[i] - vals[i - 1]);
        }
        return min_diff;
    }
};

int main()
{
    Solution sol;
    {
        TreeNode *root = new TreeNode(4);
        root->left = new TreeNode(2);
        root->right = new TreeNode(6);

        root->left->left = new TreeNode(1);
        root->left->right = new TreeNode(3);
        assert(sol.minDiffInBST(root) == 1);
    }
    {
        TreeNode *root = new TreeNode(1);
        root->left = new TreeNode(0);
        root->right = new TreeNode(48);

        root->right->left = new TreeNode(12);
        root->right->right = new TreeNode(49);
        assert(sol.minDiffInBST(root) == 1);
    }
    return 0;
}