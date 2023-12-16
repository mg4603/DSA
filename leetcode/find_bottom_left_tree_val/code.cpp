#include <iostream>
#include <assert.h>

#include <queue>
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
public:
    int findBottomLeftValue(TreeNode* root) 
    {
        
        std::queue<TreeNode *> q;
        q.push(root);
        std::vector<int> res;
        while(!q.empty())
        {
            int n = q.size();
            res.clear();
            while(n--)
            {
                TreeNode *curr = q.front();
                q.pop();
                res.push_back(curr->val);
                if(curr->left)
                {
                    q.push(curr->left);
                }
                if(curr->right)
                {
                    q.push(curr->right);
                }
            }
        }
        return res[0];
    }
};

int main()
{
    return 0;
}