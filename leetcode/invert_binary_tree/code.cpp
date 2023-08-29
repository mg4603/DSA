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
    TreeNode* invertTree(TreeNode* root) {
        if(!root)
        {
            return nullptr;
        }
        invertTree(root->left);
        invertTree(root->right);

        TreeNode *temp = root->right;

        root->right = root->left ;
        root->left = temp;
        return root;
    }
};

void assert_equal(TreeNode *head1, TreeNode *head2)
{
    if(!head1 && !head2)
    {
        assert(true);
        return;
    }
    else if(!head1 || !head2)
    {
        assert(false);
        return;
    }
    assert(head1->val == head2->val);

    assert_equal(head1->left, head2->left);
    assert_equal(head1->right, head2->right);

}

int main()
{
    Solution sol;
    {
        TreeNode *root1 = new TreeNode(4);
        root1->left = new TreeNode(2);
        root1->right = new TreeNode(7);
        root1->left->left = new TreeNode(1);
        root1->left->right = new TreeNode(3);
        root1->right->left = new TreeNode(6);
        root1->right->right = new TreeNode(9);

        TreeNode *root2 = new TreeNode(4);
        root2->left = new TreeNode(7);
        root2->right = new TreeNode(2);
        root2->left->left = new TreeNode(9);
        root2->left->right = new TreeNode(6);
        root2->right->left = new TreeNode(3);
        root2->right->right = new TreeNode(1);

        assert_equal(sol.invertTree(root1), root2);
    }
    {
        TreeNode *root1 = new TreeNode(2);
        root1->left = new TreeNode(1);
        root1->right = new TreeNode(3);

        TreeNode *root2 = new TreeNode(2);
        root2->left = new TreeNode(3);
        root2->right = new TreeNode(1);

        assert_equal(sol.invertTree(root1), root2);
    }
    {
        TreeNode *root1 = nullptr;

        TreeNode *root2 = nullptr;

        assert_equal(sol.invertTree(root1), root2);
    }

    return 0;
}