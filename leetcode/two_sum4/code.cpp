#include <iostream>
#include <assert.h>

#include <queue>
#include <set>


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        std::set<int> st;
        std::queue<TreeNode*> q;
        q.push(root);
        while(q.size())
        {
            int n(q.size());
            while(n--)
            {
                TreeNode *current = q.front();
                q.pop();
                if(st.find(current->val) != st.end())
                {
                    return true;
                }
                st.insert(k - current->val);
                if(current->left)
                {
                    q.push(current->left);
                }
                if(current->right)
                {
                    q.push(current->right);
                }
            }
        }
        return false;
    }
};

int main()
{
    Solution sol;
    {
        TreeNode *root = new TreeNode(5);
        root->left = new TreeNode(3);
        root->right = new TreeNode(6);

        root->left->left = new TreeNode(2);
        root->left->right = new TreeNode(4);

        root->right->right = new TreeNode(7);
        assert(sol.findTarget(root, 9) == true);
    }
    {
        TreeNode *root = new TreeNode(5);
        root->left = new TreeNode(3);
        root->right = new TreeNode(6);

        root->left->left = new TreeNode(2);
        root->left->right = new TreeNode(4);

        root->right->right = new TreeNode(7);
        assert(sol.findTarget(root, 28) == false);
    }
    return 0;
}