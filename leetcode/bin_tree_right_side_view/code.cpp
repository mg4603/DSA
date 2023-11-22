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
    void solve(TreeNode *root, std::vector<int> &res, int h)
    {
        if(root == nullptr)
        {
            return;
        }

        if(res.size() <= h)
        {
            res.push_back(root->val);
        }

        solve(root->right, res, h + 1);
        solve(root->left, res, h + 1);
    }
public:
    std::vector<int> rightSideView(TreeNode* root) 
    {
        std::vector<int> res;
        solve(root, res, 0);
        return res;    
    }
};

int main()
{
    Solution sol;
    {
        TreeNode *root = new TreeNode(1);

        root->right = new TreeNode(3);

        std::vector<int> res =  {1, 3};
        assert(sol.rightSideView(root) == res);
    }
    {
        TreeNode *root = nullptr;

        std::vector<int> res =  {};
        assert(sol.rightSideView(root) == res);
    }
    {
        TreeNode *root = new TreeNode(1);

        root->left = new TreeNode(2);
        root->right = new TreeNode(3);

        root->left->right = new TreeNode(5);

        root->right->right = new TreeNode(4);

        std::vector<int> res =  {1, 3, 4};
        assert(sol.rightSideView(root) == res);
    }
    return 0;
}