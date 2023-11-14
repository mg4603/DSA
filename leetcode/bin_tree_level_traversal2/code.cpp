#include <iostream>
#include <assert.h>

#include <queue>
#include <vector>
#include <algorithm>


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
    std::vector<std::vector<int>> levelOrderBottom(TreeNode* root) 
    {
        if(root == nullptr)
        {
            return {};
        }

        std::vector<std::vector<int>> res;
        std::queue<TreeNode*> q;
        q.push(root);
        int h = 0;

        while(!q.empty())
        {
            int n = q.size();
            res.push_back({});

            while(n-- > 0)
            {
                TreeNode *curr = q.front();
                q.pop();
                res[h].push_back(curr->val);
                
                if(curr->left)
                {
                    q.push(curr->left);
                }
                if(curr->right)
                {
                    q.push(curr->right);
                }
            }
            h++;
        } 
        std::reverse(res.begin(), res.end());
        return res;   
    }
};

int main()
{
    Solution sol;
    {
        TreeNode *root = new TreeNode(1);

        std::vector<std::vector<int>> res = {{1}};
        assert(sol.levelOrderBottom(root) == res);
    }
    {
        TreeNode *root = nullptr;

        std::vector<std::vector<int>> res = {};
        assert(sol.levelOrderBottom(root) == res);
    }
    {
        TreeNode *root = new TreeNode(3);

        root->left = new TreeNode(9);
        root->right = new TreeNode(20);

        root->right->left = new TreeNode(15);
        root->right->right = new TreeNode(7);

        std::vector<std::vector<int>> res = {{15, 7}, {9, 20}, {3}};
        assert(sol.levelOrderBottom(root) == res);
    }
    return 0;
}