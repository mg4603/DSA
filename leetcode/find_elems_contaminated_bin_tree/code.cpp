#include <iostream>
#include <assert.h>

#include <unordered_set>

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

const static auto fast = [] {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
};

class FindElements {
    std::unordered_set<int> vals;
public:
    void recover(TreeNode *root, int val = 0) {
        if(!root)return;
        vals.insert(val);
        recover(root->left, val * 2 + 1);
        recover(root->right, val * 2 + 2);
    }
    FindElements(TreeNode* root) {
        recover(root);
    }
    
    bool find(int target) {
        return vals.count(target);
    }
};


int main()
{
    return 0;
}