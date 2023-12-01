#include <iostream>
#include <assert.h>

#include <unordered_map>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    std::unordered_map<TreeNode*, int> mp;
    void traverse(TreeNode *root)
    {
        if(!root)
        {
            return;
        }

        if(!root->left && !root->right)
        {
            mp[root] = root->val;
            return;
        }

        int take = 0;
        int dont_take = 0;

        if(root->left && !mp.count(root->left))
        {
            traverse(root->left);
            dont_take += mp[root->left];
            if(root->left->left)
            {
                take += mp[root->left->left];
            }
            if(root->left->right)
            {
                take += mp[root->left->right];
            }
        }
        if(root->right && !mp.count(root->right))
        {
            traverse(root->right);
            dont_take += mp[root->right];
            if(root->right->left)
            {
                take += mp[root->right->left];
            }
            if(root->right->right)
            {
                take += mp[root->right->right];
            }
        }
        mp[root] = std::max(take + root->val, dont_take);
    }
public:
    int rob(TreeNode* root) {
        traverse(root);
        return mp[root];
    }
};

int main()
{
    return 0;
}