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
    void tree2str(TreeNode *root, std::string &str)
    {
        if(root == nullptr)
        {
            return;
        }
        str += std::to_string(root->val);
        if(root->left || root->right)
        {
            str += '(';
            tree2str(root->left, str);
            str += ')';
        }
        if(root->right)
        {
            str += '(';
            tree2str(root->right, str);
            str += ')';
        }

    }
public:
    std::string tree2str(TreeNode* root) {
        std::string res;
        tree2str(root, res);
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

        root->left->left = new TreeNode(4);
        assert(sol.tree2str(root) == "1(2(4))(3)");
    }
    {
        TreeNode *root = new TreeNode(1);
        root->left = new TreeNode(2);
        root->right = new TreeNode(3);

        root->left->right = new TreeNode(4);
        assert(sol.tree2str(root) == "1(2()(4))(3)");
    }
    return 0;
}