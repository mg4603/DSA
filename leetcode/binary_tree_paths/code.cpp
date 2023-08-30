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
    void binaryTreePaths(TreeNode *root, std::string temp, std::vector<std::string> &paths)
    {
        if(root == nullptr)
        {
            return;
        }
        if(root->left == nullptr && root->right == nullptr)
        {
            temp += std::to_string(root->val);
            paths.push_back(temp);
        }

        temp += std::to_string(root->val) + "->";
        binaryTreePaths(root->left, temp, paths);
        binaryTreePaths(root->right, temp, paths);
    }
    
public:
    std::vector<std::string> binaryTreePaths(TreeNode* root) {
        std::vector<std::string> res;
        binaryTreePaths(root, "", res);
        return res;
    }
};

int main()
{
    Solution sol;
    {
        TreeNode *root = new TreeNode(1);
        root->left = new TreeNode(2);
        root->right = new TreeNode(3);

        root->left->right = new TreeNode(5);

        std::vector<std::string> res = {"1->2->5","1->3"};
        assert(sol.binaryTreePaths(root) == res);
    }
    {
        TreeNode *root = new TreeNode(1);

        std::vector<std::string> res = {"1"};
        assert(sol.binaryTreePaths(root) == res);
    }
    return 0;
}