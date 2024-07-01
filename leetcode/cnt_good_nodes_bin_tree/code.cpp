#include <iostream>
#include <assert.h>

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

 auto fast = [](){
    std::ios::sync_with_stdio(0);
    return 1;
 }();
class Solution {
public:
    int goodNodes(TreeNode* root, int path_max=INT_MIN) {
        if(!root)return 0;
        int res = 0;
        if(root->val >= path_max) {
            path_max = root->val;
            res = 1;
        }
        return res + goodNodes(root->left, path_max) + 
                goodNodes(root->right, path_max);
    }
};

int main()
{
    return 0;
}