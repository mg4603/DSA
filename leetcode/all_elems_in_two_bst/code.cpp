#include <iostream>
#include <assert.h>

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
    void solve(TreeNode *root, std::vector<int> &vals)
    {
        if(!root)return;
        solve(root->left, vals);
        vals.push_back(root->val);
        solve(root->right, vals);
    }
public:
    std::vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        std::ios::sync_with_stdio(0);
        std::vector<int> res;
        std::vector<int> vals1;
        std::vector<int> vals2;

        solve(root1, vals1);
        solve(root2, vals2);

        int i = 0;
        int j = 0;
        while(i < vals1.size() && j < vals2.size()) {
            if(vals1[i] < vals2[j]) {
                res.push_back(vals1[i++]);
            }else {
                res.push_back(vals2[j++]);
            }
        }

        while(i < vals1.size()) {
            res.push_back(vals1[i++]);
        }

        while(j < vals2.size()) {
            res.push_back(vals2[j++]);
        }
        return res;
    }
};

int main()
{
    return 0;
}