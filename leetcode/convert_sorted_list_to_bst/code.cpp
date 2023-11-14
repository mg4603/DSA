#include <iostream>
#include <assert.h>

#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    TreeNode *helper(std::vector<int> &vec, int l, int r)
    {
        if(l > r)
        {
            return nullptr;
        }

        int mid = (l + r)/ 2;
        TreeNode *root = new TreeNode(vec[mid]);
        root->left = helper(vec, l, mid - 1);
        root->right = helper(vec, mid + 1, r); 
        return root;
    }
public:
    TreeNode* sortedListToBST(ListNode* head) 
    {
        std::vector<int> vec;
        while(head != nullptr)
        {
            vec.push_back(head->val);
            head = head->next;
        }
        return helper(vec, 0, vec.size() - 1);
    }
};

int main()
{
    return 0;
}