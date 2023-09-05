#include <iostream>
#include <assert.h>

#include <map>
#include <vector>


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    void findMode(TreeNode *root, std::map<int, int> &freq)
    {
        if(root == nullptr)
        {
            return;
        }
        findMode(root->left, freq);
        freq[root->val]++;
        findMode(root->right, freq);
    }
public:
    std::vector<int> findMode(TreeNode* root) {
        std::map<int, int> freq;
        findMode(root, freq);
        std::vector<int> res;
        
        int mode(0);
        for(auto pair: freq)
        {
            if(pair.second > mode)
            {
                mode = pair.second;
            }
        }
        for(auto pair: freq)
        {
            if(pair.second == mode)
            {
                res.push_back(pair.first);
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        TreeNode *root = new TreeNode(1);
        root->right = new TreeNode(2);
        root->right->left = new TreeNode(2);
        assert(sol.findMode(root) == std::vector<int>({2}));
    }
    {
        TreeNode *root = new TreeNode(0);
        assert(sol.findMode(root) == std::vector<int>({0}));
    }
    return 0;
}