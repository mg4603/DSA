#include <iostream>
#include <assert.h>

#include <queue>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        std::queue<TreeNode*> q;
        std::queue<TreeNode*> qc;
        q.push(original);
        qc.push(cloned);

        while(q.size())
        {
            int n = q.size();
            while(n--)
            {
                TreeNode *current = q.front();
                q.pop();

                TreeNode *cloned_current = qc.front();
                qc.pop();
                if(current == target)
                {
                    return cloned_current;
                }

                if(current->left != nullptr)
                {
                    qc.push(cloned_current->left);
                    q.push(current->left);
                }
                if(current->right != nullptr)
                {
                    qc.push(cloned_current->right);
                    q.push(current->right);
                }
            }
        }
        return nullptr;
    }
};

int main()
{
    return 0;
}