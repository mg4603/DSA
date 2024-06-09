#include <iostream>
#include <assert.h>

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
    bool solve(TreeNode *r1, TreeNode *r2) {
        if(!r1 && !r2)return true;
        if(!r1 || !r2)return false;
        if((!r1->left && !r2->right) || 
           (!r1->right && !r2->left) || 
           (r1->left && r2->right && 
            r1->left->val == r2->right->val)) {
           TreeNode *temp = r2->right;
           r2->right = r2->left;
           r2->left = temp; 
        }
        
        return r1->val == r2->val && 
             solve(r1->left, r2->left) && 
             solve(r1->right, r2->right);
    }
public:
    bool flipEquiv(TreeNode* r1, TreeNode* r2) {
        if(!r1 && !r2)return true;
        if(!r1 || !r2)return false;
        return (r1->val == r2->val) && solve(r1, r2);        
    }
};

int main()
{
    Solution sol;
    {
        TreeNode *r1 = new TreeNode(1);
        r1->left = new TreeNode(2);

        TreeNode *r2 = new TreeNode(1);
        r2->right = new TreeNode(2);
        bool res = true;
        assert(sol.flipEquiv(r1, r2) == res);
    }
    return 0;
}