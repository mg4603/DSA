#include <iostream>
#include <assert.h>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    TreeNode *res;

    void helper(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if(root == nullptr)
        {
            return;
        }

        helper(root->left, p, q);
        if(root->val >= p->val && root->val <= q->val)
        {
            res = root;
            return;
        }
        helper(root->right, p, q);
    }
public:
    Solution(): res(nullptr){};

    TreeNode* lowestCommonAncestor(TreeNode* root, 
                                   TreeNode* p, 
                                   TreeNode* q) 
    {
        if(p->val > q->val)
        {
            TreeNode *temp = p;
            p = q;
            q = temp;
        }
        helper(root, p, q);
        return res;        
    }
};

int main()
{
    return 0;
}