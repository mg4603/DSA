#include <iostream>
#include <assert.h>

#include <vector>
#include <unordered_map>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    TreeNode *helper(std::vector<int> &pre, 
                     std::unordered_map<int, int> &mp, 
                     int &idx, int in_begin, int in_end)
    {
        if(idx >= pre.size() || in_begin > in_end)
        {
            return nullptr;
        }

       TreeNode *root = new TreeNode(pre[idx]);
        
        int root_idx = mp[pre[idx++]];

        root->left = helper(pre, mp, idx, in_begin, root_idx - 1);
        root->right = helper(pre, mp, idx, root_idx + 1, in_end);
        return root;
    }
public:
    TreeNode* buildTree(std::vector<int>& preorder, 
                        std::vector<int>& inorder) 
    {
        std::unordered_map<int, int> in_pos_mp;
        int n = inorder.size();
        for(int i = 0; i < n; i++)
        {
            in_pos_mp[inorder[i]] = i;
        }
        int idx = 0;
        return helper(preorder, in_pos_mp, idx, 0, n);
    }
};

int main()
{
    return 0;
}