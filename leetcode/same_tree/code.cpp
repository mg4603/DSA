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
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q)
        {
            return true;
        }
        if(!p || !q)
        {
            return false;
        }
        bool root = (p->val == q->val);
        bool ltree = isSameTree(p->left, q->left);
        bool rtree = isSameTree(p->right, q->right);
        return root && ltree && rtree;
    }
};

int main()
{
    Solution sol;
    {
        TreeNode *p = new TreeNode(1);
        p->left = new TreeNode(2);
        p->right = new TreeNode(3);

        TreeNode *q = new TreeNode(1);
        q->left = new TreeNode(2);
        q->right = new TreeNode(3);

        assert(sol.isSameTree(p, q) == true);
    }
    {
        TreeNode *p = new TreeNode(1);
        p->left = new TreeNode(2);

        TreeNode *q = new TreeNode(1);
        q->right = new TreeNode(2);

        assert(sol.isSameTree(p, q) == false);
    }
    {
        TreeNode *p = new TreeNode(1);
        p->left = new TreeNode(2);
        p->right = new TreeNode(1);

        TreeNode *q = new TreeNode(1);
        q->left = new TreeNode(1);
        q->right = new TreeNode(2);

        assert(sol.isSameTree(p, q) == false);
    }
    return 0;
}