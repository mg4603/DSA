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
    TreeNode *start;
    TreeNode *last;

    void inorder(TreeNode *root)
    {
        if(root == nullptr)
        {
            return;
        }
        inorder(root->left);
        if(start == nullptr)
        {
            start = root;
            last = root;
        }
        else
        {
            last->right = root;
        }
        root->left = nullptr; 
        last = root;       
        inorder(root->right);
    }
public:
    Solution()
    {
        start = nullptr;
        last = nullptr;
    }
    TreeNode* increasingBST(TreeNode* root) {
       inorder(root);
       return start; 
    }
};

void assert_equal(TreeNode *r1, TreeNode *r2)
{
    if(r1 == nullptr && r2 == nullptr)
    {
        assert(true);
        return;
    }
    if(r1 == nullptr || r2 == nullptr)
    {
        assert(false);
        return;
    }
    assert_equal(r1->left, r2->left);
    assert(r1->val == r2->val);
    assert_equal(r1->right, r2->right);
}

int main()
{
    Solution sol;
    {
        TreeNode *root = new TreeNode(5);
        root->left = new TreeNode(3);
        root->right = new TreeNode(6);

        root->left->left = new TreeNode(2);
        root->left->right = new TreeNode(4);

        root->left->left->left = new TreeNode(1);

        root->right->right = new TreeNode(8);

        root->right->right->left = new TreeNode(7);
        root->right->right->right = new TreeNode(9);

        TreeNode *res_root = new TreeNode(1);
        res_root->right = new TreeNode(2);
        res_root->right->right = new TreeNode(3);
        res_root->right->right->right = new TreeNode(4);
        res_root->right->right->right->right = new TreeNode(5);
        res_root->right->right->right->right->right = new TreeNode(6);
        res_root->right->right->right->right->right->right = new TreeNode(7);
        res_root->right->right->right->right->right->right->right = new TreeNode(8);
        res_root->right->right->right->right->right->right->right->right = new TreeNode(9);

        TreeNode *output = sol.increasingBST(root);
        assert_equal(output, res_root);
    }
    Solution sol1;
    {
        TreeNode *root = new TreeNode(5);
        root->left = new TreeNode(1);
        root->right = new TreeNode(7);

        TreeNode *res_root = new TreeNode(1);
        res_root->right = new TreeNode(5);
        res_root->right->right = new TreeNode(7);

        TreeNode *output = sol1.increasingBST(root);
        assert_equal(output, res_root);
    }
    return 0;
}