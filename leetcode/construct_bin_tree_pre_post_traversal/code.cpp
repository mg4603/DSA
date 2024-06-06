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
    int pre = 0;
    int post = 0;
public:
    TreeNode* constructFromPrePost(std::vector<int>& preorder, 
                                    std::vector<int>& postorder) {
        TreeNode *root = new TreeNode(preorder[pre++]);

        if(root->val != postorder[post]) {
            root->left = constructFromPrePost(preorder, postorder);
        }
        if(root->val != postorder[post]) {
            root->right = constructFromPrePost(preorder, postorder);
        }
        post++;
        return root;
    }
};

int main()
{
    return 0;
}