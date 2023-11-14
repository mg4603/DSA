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
    TreeNode *helper(std::vector<int> &post, 
                     std::unordered_map<int, int> &in_map, 
                     int &idx, int in_begin, int in_end)
    {
        if(in_begin > in_end || idx < 0)
        {
            return nullptr;
        }

        TreeNode *root = new TreeNode(post[idx]);
        int root_idx = in_map[post[idx--]];

        root->right = helper(post, in_map, idx, root_idx + 1, in_end);
        root->left = helper(post, in_map, idx, in_begin, root_idx - 1);
        return root;
    }
public:
    TreeNode* buildTree(std::vector<int>& inorder, 
                        std::vector<int>& postorder) 
    {
        std::unordered_map<int, int> mp;
        for(int i = 0; i < inorder.size(); i++)
        {
            mp[inorder[i]] = i;
        }
        int idx = postorder.size() - 1;
        return helper(postorder, mp, idx, 0, idx);
    }
};

int main()
{
    return 0;
}