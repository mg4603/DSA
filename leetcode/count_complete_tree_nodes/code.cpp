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
  void countNodes(TreeNode *root, int &count)
  {
    if(!root)
    {
      return;
    } 
    countNodes(root->left, count);
    count++;
    countNodes(root->right, count);
  }
public:
    int countNodes(TreeNode* root) {
        int count(0);
        countNodes(root, count);
        return count;
    }
};

int main()
{
    Solution sol;
    {
        TreeNode *root = new TreeNode(1);

        root->left = new TreeNode(2);
        root->right = new TreeNode(3);

        root->left->left = new TreeNode(4);
        root->left->right = new TreeNode(5);

        root->right->left = new TreeNode(6);
        assert(sol.countNodes(root) == 6);
    }
    {
        TreeNode *root = nullptr;
        assert(sol.countNodes(root) == 0);
    }
    {
        TreeNode *root = new TreeNode(1);
        assert(sol.countNodes(root) == 1);
    }
    return 0;
}