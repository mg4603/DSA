#include <iostream>
#include <assert.h>

#include <stack>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class BSTIterator {
    TreeNode *curr;
    std::stack<TreeNode*> st;
public:
    BSTIterator(TreeNode* root) {
        curr = root;
    }
    
    int next() 
    {
        int res = 0;
        while(!st.empty() || curr != nullptr)
        {
            if(curr == nullptr)
            {
                curr = st.top();
                st.pop();
                res = curr->val;
                curr = curr->right;
                break;
            }
            else
            {
                st.push(curr);
                curr = curr->left;
            }
        }
        return res;    
    }
    
    bool hasNext() {
        return (curr || !st.empty());
    }
};

int main()
{
    TreeNode *root = new TreeNode(7);

    root->left = new TreeNode(3);
    root->right = new TreeNode(15);

    root->right->left = new TreeNode(9);
    root->right->right = new TreeNode(20);

    BSTIterator obj(root);
    
    assert(obj.next() == 3);
    assert(obj.next() == 7);
    assert(obj.hasNext() == true);
    assert(obj.next() == 9);
    assert(obj.hasNext() == true);
    assert(obj.next() == 15);
    assert(obj.hasNext() == true);
    assert(obj.next() == 20);
    assert(obj.hasNext() == false);
    return 0;
}