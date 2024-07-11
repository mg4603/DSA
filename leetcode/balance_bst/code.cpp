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
    void inorder(TreeNode *root, std::vector<int> &sorted_arr) {
        if(!root)return;
        inorder(root->left, sorted_arr);
        sorted_arr.push_back(root->val);
        inorder(root->right, sorted_arr);
    }
    TreeNode* getBST(std::vector<int> &sorted_arr, int start, int end) {
        if(start > end)return nullptr;
        int mid = (start + end) / 2;
        TreeNode *root = new TreeNode(sorted_arr[mid]);
        root->left = getBST(sorted_arr, start, mid -1);
        root->right = getBST(sorted_arr, mid + 1, end);
        return root;
    }
public:
    TreeNode* balanceBST(TreeNode* root) {
        std::vector<int> sorted_arr;    
        inorder(root, sorted_arr);
        return getBST(sorted_arr, 0, sorted_arr.size() - 1);
    }
};

int main()
{
    return 0;
}