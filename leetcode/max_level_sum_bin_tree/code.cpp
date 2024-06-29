#include <iostream>
#include <assert.h>

#include <queue>
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

class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        std::ios::sync_with_stdio(0);
        int max_level = 1;
        int max_sum = INT_MIN;
        std::queue<TreeNode *> q;
        q.push(root);

        int level = 0;
        while(!q.empty()) {
            int n = q.size();
            int level_sum = 0;
            while(n--) {
                TreeNode *node = q.front();
                q.pop();
                level_sum += node->val;
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            }
            level++;
            if(level_sum > max_sum) {
                max_sum = level_sum;
                max_level = level;
            }
        }
        return max_level;
    }
};

int main()
{
    Solution sol;
    {
        TreeNode *root = new TreeNode(1);
        root->left = new TreeNode(7);
        root->right = new TreeNode(0);

        root->left->left = new TreeNode(7);
        root->left->right = new TreeNode(-8);

        int res = 2;
        assert(sol.maxLevelSum(root) == res);
    }
    return 0;
}