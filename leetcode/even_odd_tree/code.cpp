#include <iostream>
#include <assert.h>

#include <queue>
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
public:
    bool isEvenOddTree(TreeNode* root) {
        std::ios::sync_with_stdio(0);
        int lvl = 0;
        std::queue<TreeNode *> q;
        q.push(root);

        while(!q.empty()) {
            int n = q.size();

            std::vector<int> lvlVals;
            while(n--) {
                TreeNode *top = q.front();
                q.pop();
                if(top->left) q.push(top->left);
                if(top->right) q.push(top->right);

                lvlVals.push_back(top->val);
            }
            if(lvl % 2) {
                std::reverse(lvlVals.begin(), lvlVals.end());
            }
            for(int i = 0; i < lvlVals.size(); i++) {
                if(lvl % 2) {
                    if(lvlVals[i] % 2)return false;
                } else {
                    if(lvlVals[i] % 2 == 0)return false;
                }
                if(i > 0 && lvlVals[i] <= lvlVals[i - 1])
                    return false;
            }
            lvl++;
        }
        return true;
    }
};

int main()
{
    return 0;
}