#include <iostream>
#include <assert.h>

#include <vector>
#include <queue>

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
    std::vector<int> largestValues(TreeNode* root) 
    {
        if(!root)
        {
            return {};
        }
        std::queue<TreeNode*> q;
        q.push(root);

        std::vector<int> res;
        while(!q.empty())
        {
            int row_max = std::numeric_limits<int>::min();
            int n = q.size();
            while(n--)
            {
                TreeNode *curr = q.front();
                q.pop();
                if(curr->val > row_max)
                {
                    row_max = curr->val;
                }
                if(curr->left)
                {
                    q.push(curr->left);
                }
                if(curr->right)
                {
                    q.push(curr->right);
                }
            }
            res.push_back(row_max);
        }
        return res;    
    }
};

int main()
{
    return 0;
}