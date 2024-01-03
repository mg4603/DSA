#include <iostream>
#include <assert.h>

#include <vector>
#include <algorithm>

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
    TreeNode *construct(std::vector<int> &nums, int l, int r)
    {
        if(l == r)
        {
            return nullptr;
        }

        auto it = std::max_element(nums.begin() + l, 
                                   nums.begin() + r);

        TreeNode *curr = new TreeNode(*it);
        curr->left = construct(nums, l, it - nums.begin());
        curr->right = construct(nums, it - nums.begin() + 1, r);
        return curr;
    }
public:
    TreeNode* constructMaximumBinaryTree(std::vector<int>& nums) {
        return construct(nums, 0, nums.size());
    }
};

int main()
{
    return 0;
}