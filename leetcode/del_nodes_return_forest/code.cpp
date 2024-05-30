#include <iostream>
#include <assert.h>

#include <unordered_set>
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
    TreeNode* solve(TreeNode *root, 
                    std::vector<TreeNode*> &res, 
                    std::unordered_set<int> &to_del, 
                    bool is_root) {
        if(!root)return nullptr;

        bool deleted = to_del.count(root->val);
        if(is_root && !deleted)res.push_back(root);
        root->left = solve(root->left, res, to_del, deleted);
        root->right = solve(root->right, res, to_del, deleted);
        return deleted ? nullptr: root;
    }
public:
    std::vector<TreeNode*> delNodes(TreeNode* root, 
                            std::vector<int>& to_delete) {
        std::unordered_set<int> to_del;
        for(int &num: to_delete) {
            to_del.insert(num);
        }
        std::vector<TreeNode*> res;
        solve(root, res, to_del, true);
        return res;
    }
};

int main()
{
    return 0;
}