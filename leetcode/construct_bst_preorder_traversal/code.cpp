#include <iostream>
#include <assert.h>

#include <vector>
#include <climits>

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

 const static auto fast = [] {
    std::ios::sync_with_stdio(0);
    return 0;
 };
class Solution {
    int idx = 0;
public:
    TreeNode* bstFromPreorder(std::vector<int>& preorder, 
                            int large = INT_MAX) {
        if(idx >= preorder.size() || 
           preorder[idx] > large)return nullptr;
        TreeNode *root = new TreeNode(preorder[idx++]);
        root->left = bstFromPreorder(preorder, root->val);
        root->right = bstFromPreorder(preorder, large);
        return root;
    }
};

int main()
{
    return 0;
}