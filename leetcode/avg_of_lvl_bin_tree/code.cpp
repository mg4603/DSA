#include <iostream>
#include <assert.h>

#include <vector>
#include <queue>

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
    std::vector<double> averageOfLevels(TreeNode* root) {
        std::queue<TreeNode*> q;
        q.push(root);
        std::vector<double> res;
        while(q.size())
        {
            int n = q.size();
            double sum(0);
            int divisor(n);
            while(n--)
            {
                TreeNode *current = q.front();
                sum += current->val;
                q.pop();
                if(current->left)
                {
                    q.push(current->left);
                }
                if(current->right)
                {
                    q.push(current->right);
                }
            }
            res.push_back(sum / divisor);
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        TreeNode *root = new TreeNode(3);
        root->left = new TreeNode(9);
        root->right = new TreeNode(20);
        
        root->right->left = new TreeNode(15);
        root->right->right = new TreeNode(7);

        std::vector<double> res = {3.00000,14.50000,11.00000};
        assert(sol.averageOfLevels(root) == res);
    }
    {
        TreeNode *root = new TreeNode(3);
        root->left = new TreeNode(9);
        root->right = new TreeNode(20);
        
        root->left->left = new TreeNode(15);
        root->left->right = new TreeNode(7);

        std::vector<double> res = {3.00000,14.50000,11.00000};
        assert(sol.averageOfLevels(root) == res);
    }
    return 0;
}