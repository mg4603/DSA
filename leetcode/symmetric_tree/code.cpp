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
    bool checkSymmetry(TreeNode *p, TreeNode *q)
    {
        if(!p && !q)
        {
            return true;
        }
        if(!p || !q)
        {
            return false;
        }
        bool root = (p->val == q->val);
        bool ltree = checkSymmetry(p->left, q->right);
        bool rtree = checkSymmetry(p->right, q->left);
        return root && ltree && rtree;
    }
public:
    bool isSymmetric(TreeNode* root) {
        if(!root->left && !root->right)
        {
            return true;
        }
        if(!root->left || !root->right)
        {
            return false;
        }
        return checkSymmetry(root->left, root->right);
    }
};

int main()
{
    Solution sol;
    {
        TreeNode *root = new TreeNode(1);
        root->left = new TreeNode(2);
        root->right = new TreeNode(2);

        root->left->left = new TreeNode(3);
        root->left->right = new TreeNode(4);
        
        root->right->left = new TreeNode(4);
        root->right->right = new TreeNode(3);

        assert(sol.isSymmetric(root) == true);
    }
    {
        TreeNode *root = new TreeNode(1);
        root->left = new TreeNode(2);
        root->right = new TreeNode(2);

        root->left->right = new TreeNode(3);
        
        root->right->right = new TreeNode(3);

        assert(sol.isSymmetric(root) == false);
    }
    return 0;
}