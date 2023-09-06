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
    bool isSame(TreeNode *root1, TreeNode *root2)
    {
        if(root1 == nullptr && root2 == nullptr)
        {
            return true;
        }
        if(root1 == nullptr || root2 == nullptr)
        {
            return false;
        }
        bool center = root1->val == root2->val;
        return isSame(root1->left, root2->left) && isSame(root1->right, root2->right) && center;
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(subRoot == nullptr)
        {
            return true;
        }
        if(root == nullptr)
        {
            return false;
        }
        if(isSame(root, subRoot))
        {
            return true;
        }
        
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};

int main()
{
    Solution sol;
    {
        TreeNode *root = new TreeNode(3);
        root->left = new TreeNode(4);
        root->right = new TreeNode(5);

        root->left->left = new TreeNode(1);
        root->left->right = new TreeNode(2);

        TreeNode *subroot = new TreeNode(4);
        subroot->left = new TreeNode(1);
        subroot->right = new TreeNode(2);
        assert(sol.isSubtree(root, subroot) == true);
    }
    {
        TreeNode *root = new TreeNode(3);
        root->left = new TreeNode(4);
        root->right = new TreeNode(5);

        root->left->left = new TreeNode(1);
        root->left->right = new TreeNode(2);
        root->left->right->left = new TreeNode(0);

        TreeNode *subroot = new TreeNode(4);
        subroot->left = new TreeNode(1);
        subroot->right = new TreeNode(2);
        assert(sol.isSubtree(root, subroot) == false);
    }
    return 0;
}