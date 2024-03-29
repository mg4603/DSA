#include <iostream>
#include <assert.h>

#include "../helper/list/list.cpp"

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
    bool helper(ListNode<int> *head, TreeNode *root)
    {
        if(!head)return true;
        if(!root)return false;
        return head->val == root->val && 
                (helper(head->next, root->left) || 
                helper(head->next, root->right));
    }
public:
    bool isSubPath(ListNode<int>* head, TreeNode* root) {
        if(!root)return false;
        return helper(head, root) || 
                isSubPath(head, root->left) || 
                isSubPath(head, root->right);
    }
};

int main()
{
    return 0;
}