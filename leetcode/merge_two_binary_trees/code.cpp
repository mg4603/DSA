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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(root2 == nullptr)
        {
            return root1;
        }
        if(root1 == nullptr)
        {
            return root2;
        }
        TreeNode *root = new TreeNode(root1->val + root2->val);
        root->left = mergeTrees(root1->left, root2->left);
        root->right = mergeTrees(root1->right, root2->right);
        return root;
    }
};

void assert_equal(TreeNode *root1, TreeNode *root2)
{
    if(root1 == nullptr && root2 == nullptr)
    {
        assert(true);
        return;
    }
    if(root1 == nullptr || root2 == nullptr)
    {
        assert(false);
        return;
    }
    assert(root1->val == root2->val);
    assert_equal(root1->left, root2->left);
    assert_equal(root1->right, root2->right);
}

int main()
{
    Solution sol;
    {
        TreeNode *root1 = new TreeNode(1);
        root1->left = new TreeNode(3);
        root1->right = new TreeNode(2);
        root1->left->left = new TreeNode(5);

        TreeNode *root2 = new TreeNode(2);
        root2->left = new TreeNode(1);
        root2->right = new TreeNode(3);

        root1->left->right = new TreeNode(4);

        root1->right->right = new TreeNode(7);

        TreeNode *merged_root = new TreeNode(3);
        merged_root->left = new TreeNode(4);
        merged_root->right = new TreeNode(5);

        merged_root->left->left = new TreeNode(5);
        merged_root->left->right = new TreeNode(4);

        merged_root->right->right = new TreeNode(7);
        
        assert_equal(sol.mergeTrees(root1, root2), merged_root);
    }
    {
        TreeNode *root1 = new TreeNode(1);
        TreeNode *root2 = new TreeNode(1);
        root2->left = new TreeNode(2);

        TreeNode *merged_root = new TreeNode(2);
        merged_root->left = new TreeNode(2);
        assert_equal(sol.mergeTrees(root1, root2), merged_root);
    }
    return 0;
}