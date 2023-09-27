#include <iostream>
#include <assert.h>

#include <vector>


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    void getLeaves(TreeNode *root, std::vector<int> &leaves)
    {
        if(root == nullptr)
        {
            return;
        }
        if(root->left == nullptr && root->right == nullptr)
        {
            leaves.push_back(root->val);
        }
        getLeaves(root->left, leaves);
        getLeaves(root->right, leaves);
    }
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        std::vector<int> root1_leaves;
        std::vector<int> root2_leaves;
        getLeaves(root1, root1_leaves);
        getLeaves(root2, root2_leaves);

        return root1_leaves == root2_leaves;
    }
};

int main()
{
    Solution sol;
    {
        TreeNode *root1 = new TreeNode(3);
        root1->left = new TreeNode(5);
        root1->right = new TreeNode(1);
        
        root1->left->left = new TreeNode(6);
        root1->left->right = new TreeNode(2);

        root1->right->left = new TreeNode(9);
        root1->right->right = new TreeNode(8);

        root1->left->right->left = new TreeNode(7);
        root1->left->right->right = new TreeNode(4);

        TreeNode *root2 = new TreeNode(3);
        
        root2->left = new TreeNode(5);
        root2->right = new TreeNode(1);

        root2->left->left = new TreeNode(6);
        root2->left->right = new TreeNode(7);

        root2->right->left = new TreeNode(4);
        root2->right->right = new TreeNode(2);

        root2->right->right->left = new TreeNode(9);
        root2->right->right->right = new TreeNode(8);

        assert(sol.leafSimilar(root1, root2) == true);
    }
        {
        TreeNode *root1 = new TreeNode(1);

        root1->left = new TreeNode(2);
        root1->right = new TreeNode(3);
        

        TreeNode *root2 = new TreeNode(1);
        
        root2->left = new TreeNode(3);
        root2->right = new TreeNode(2);

        assert(sol.leafSimilar(root1, root2) == false);
    }
    return 0;
}