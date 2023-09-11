#include <iostream>
#include <assert.h>

#include <vector>
#include <algorithm>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    void inorderTraversal(TreeNode *root, std::vector<int> &vec)
    {
        if(root == nullptr)
        {
            return;
        }
        inorderTraversal(root->left, vec);
        vec.push_back(root->val);
        inorderTraversal(root->right, vec);
    }
public:
    int findSecondMinimumValue(TreeNode* root) {
        std::vector<int> vec;
        inorderTraversal(root, vec);
        std::sort(vec.begin(), vec.end());
        vec.erase(std::unique(vec.begin(), vec.end()), vec.end());
        return vec.size() >= 2?vec[1] : -1;
    }
};

int main()
{
    Solution sol;
    {
        TreeNode *root = new TreeNode(2);
        root->left = new TreeNode(2);
        root->right = new TreeNode(5);

        root->right->left = new TreeNode(5);
        root->right->right = new TreeNode(7);
        assert(sol.findSecondMinimumValue(root) == 5);
    }
    {
        TreeNode *root = new TreeNode(2);
        root->left = new TreeNode(2);
        root->right = new TreeNode(2);

        assert(sol.findSecondMinimumValue(root) == -1);
    }
    return 0;
}