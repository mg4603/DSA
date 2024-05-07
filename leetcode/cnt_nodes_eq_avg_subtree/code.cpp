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

std::array<int, 2> operator+(const std::array<int, 2> &l,
                    const std::array<int, 2> &r)
{
    return {l[0] + r[0], l[1] + r[1]};
}

class Solution {
    std::array<int, 2> helper(TreeNode *root, int &res)
    {
        std::ios::sync_with_stdio(0);
        if(!root->left && !root->right)
        {
            res++;
            return {root->val, 1};
        }
        std::array<int, 2> temp{0, 0};
        if(root->left)
        {
            temp = temp + helper(root->left, res);
        }

        if(root->right)
        {
            temp = temp + helper(root->right, res);
        }

        temp[0] += root->val;
        temp[1]++;
        if(temp[0] / temp[1] == root->val)res++;

        return temp;
    }
public:
    int averageOfSubtree(TreeNode* root) {
        int res = 0;
        helper(root, res);
        return res;
    }
};

int main()
{
    return 0;
}