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
    void solve(TreeNode *node1, TreeNode *node2, int level=1)
    {
        if(!node1 && !node2)return;

        if(level % 2 == 1)
        {
            int temp = node1->val;
            node1->val = node2->val;
            node2->val = temp;
        }
        solve(node1->left, node2->right, level + 1);
        solve(node1->right, node2->left, level + 1);
    }
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        solve(root->left, root->right);
        return root;
    }
};

int main()
{
    return 0;
}