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
    TreeNode *first;
    TreeNode *second;
    TreeNode *prev;
    void inorder(TreeNode *root)
    {
        if(root == nullptr)
        {
            return;
        }
        inorder(root->left);
        if(prev != nullptr && root->val < prev->val)
        {
            if(!first)
            {
                first = prev;
            }
            second = root;
        }
        prev = root;
        inorder(root->right);
    }
public:
    void recoverTree(TreeNode* root) {
        first = nullptr;
        second = nullptr;
        prev = nullptr;

        inorder(root);
        int temp = first->val;
        first->val = second->val;
        second->val = temp;
    }
};

void tree_equal(TreeNode *a, TreeNode *b)
{
    if(!a || !b)
    {
        assert(a == b);
        return;
    }
    
    tree_equal(a->left, b->left);
    assert(a->val == b->val);
    tree_equal(a->right, b->right);
}

int main()
{
    Solution sol;
    {
        TreeNode *root = new TreeNode(1);
        root->left = new TreeNode(3);
        root->left->right = new TreeNode(2);
        sol.recoverTree(root);
        
        TreeNode *res = new TreeNode(3);
        res->left = new TreeNode(1);
        res->left->right = new TreeNode(2);

        tree_equal(root, res);
    }
    {
        TreeNode *root = new TreeNode(3);
        root->left = new TreeNode(1);
        root->right = new TreeNode(4);
        root->right->left = new TreeNode(2);
        sol.recoverTree(root);
        
        TreeNode *res = new TreeNode(2);
        res->left = new TreeNode(1);
        res->right = new TreeNode(4);
        res->right->left = new TreeNode(3);
        
        tree_equal(root, res);
    }
    return 0;
}