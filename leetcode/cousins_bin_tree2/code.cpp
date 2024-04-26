#include <iostream>
#include <assert.h>

#include <vector>

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
    std::vector<int> l_sum;
    void level_sum(TreeNode *n, int depth = 0)
    {
        if(!n)return;

        if(depth >= l_sum.size())l_sum.resize(depth + 1);

        l_sum[depth] += n->val;
        level_sum(n->left, depth + 1);
        level_sum(n->right, depth + 1);
    }

    void update_sum(TreeNode *n, long long sib_val, int depth = 0)
    {
        if(!n)return;
        n->val = l_sum[depth] - sib_val;
        sib_val = (n->left ? n->left->val : 0) + 
                    (n->right ? n->right->val: 0);
        update_sum(n->left, sib_val, depth + 1);
        update_sum(n->right, sib_val, depth + 1);
    }
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        level_sum(root);
        update_sum(root, root->val);
        return root;    
    }
};

int main()
{
    return 0;
}