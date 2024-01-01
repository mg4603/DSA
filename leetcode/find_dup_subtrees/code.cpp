#include <iostream>
#include <assert.h>

#include <map>
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
    std::string helper(TreeNode *root, 
                       std::map<std::string, int> &mp, 
                       std::vector<TreeNode*> &res)
    {
        if(!root)return "#";

        std::string s = helper(root->left, mp, res) + "," + 
                        helper(root->right, mp, res) + "," + 
                        std::to_string(root->val);

        int cnt = ++mp[s];
        if(cnt == 2)
        {
            res.push_back(root);
        }
        return s;
    }
public:
    std::vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) 
    {
        std::map<std::string, int> mp;
        std::vector<TreeNode*> res;
        helper(root, mp, res);
        return res;     
    }
};

int main()
{
    return 0;
}