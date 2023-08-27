#include <iostream>
#include <assert.h>

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
    int minDepth(TreeNode* root) {
        if(root == nullptr)
        {
            return 0;
        }
        std::queue<TreeNode*> q;
        q.push(root);
        int depth(0);
        while(!q.empty())
        {
            int size(q.size());
            while(size--)
            {
                TreeNode *current = q.front();
                q.pop();

                if(!current->left && !current->right)
                {
                    return depth + 1;
                }
                if(current->left)
                {
                    q.push(current->left);
                }
                if(current->right)
                {
                    q.push(current->right);
                }
            }
            depth++;
        }
        return depth;
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
        assert(sol.minDepth(root) == 2);
    }
    {
        TreeNode *root = new TreeNode(2);
        root->right = new TreeNode(3);
        
        root->right->right = new TreeNode(4);

        root->right->right->right = new TreeNode(5);
        
        root->right->right->right->right = new TreeNode(6);
        
        assert(sol.minDepth(root) == 5);
    }
    return 0;
}