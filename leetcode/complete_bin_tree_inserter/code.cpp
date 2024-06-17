#include <iostream>
#include <assert.h>

#include <queue>

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

class CBTInserter {
    TreeNode *root;
public:
    CBTInserter(TreeNode* root) {
        std::ios::sync_with_stdio(0);
        this->root = root;
    }
    
    int insert(int val) {
        std::queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int n = q.size();
            while(n--) {
                TreeNode *temp = q.front();
                q.pop();
                if(temp->left)q.push(temp->left);
                else {
                    temp->left = new TreeNode(val);
                    return temp->val;
                }
                if(temp->right)q.push(temp->right);
                else {
                    temp->right = new TreeNode(val);
                    return temp->val;
                }
            }          
        }
        return -1;
    }
    
    TreeNode* get_root() {
        return root;
    }
};

int main()
{
    CBTInserter cBTInserter(new TreeNode(1));
    cBTInserter.insert(2);
    assert(cBTInserter.insert(3) == 1);
    assert(cBTInserter.insert(4) == 2);
    cBTInserter.get_root();


    return 0;
}