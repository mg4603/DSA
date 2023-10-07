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
    int x_height;
    int y_height;
    TreeNode *x_parent;
    TreeNode *y_parent;
    void traverse(TreeNode *root, int x, int y, int dep)
    {
        if(root == nullptr)
        {
            return;
        }
        dep++;

        if(root->val == x)
        {
            x_height = dep;
        }
        if(root->val == y)
        {
            y_height = dep;
        }

        if(root->left)
        {
            if(root->left->val == x)
            {
                x_parent = root;
            }
            if(root->left->val == y)
            {
                y_parent = root;
            }
        }
        if(root->right)
        {
            if(root->right->val == x)
            {
                x_parent = root;
            }
            if(root->right->val == y)
            {
                y_parent = root;
            }
        }
        traverse(root->left, x, y, dep);
        traverse(root->right, x, y, dep);
    }
public:
    bool isCousins(TreeNode* root, int x, int y) {
        x_height = -1;
        y_height = -1;
        x_parent = nullptr;
        y_parent = nullptr;
        traverse(root, x, y, 0);
        return (x_height == y_height && x_height != -1 && x_parent != y_parent);
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

        int x = 4;
        int y = 3;

        bool output = false;
        assert(sol.isCousins(root, x, y) == output);
    }
    {
        TreeNode *root = new TreeNode(1);
        root->left = new TreeNode(2);
        root->right = new TreeNode(3);

        root->left->right = new TreeNode(4);
        root->right->right = new TreeNode(5);
        int x = 5;
        int y = 4;

        bool output = true;
        assert(sol.isCousins(root, x, y) == output);
    }
    {
        TreeNode *root = new TreeNode(1);
        root->left = new TreeNode(2);
        root->right = new TreeNode(3);

        root->left->right = new TreeNode(4);
        int x = 2;
        int y = 3;

        bool output = false;
        assert(sol.isCousins(root, x, y) == output);
    }
    return 0;
}