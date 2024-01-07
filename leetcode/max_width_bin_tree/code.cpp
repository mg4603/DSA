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

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(!root)return 0;

        std::queue<std::pair<TreeNode *, long long>> q;
        q.push({root, 0});
        int res = 0;
        while(!q.empty())
        {
            long long start = q.front().second;
            long long end = q.back().second;
            res = std::max(res, 
                        static_cast<int>(end - start + 1));

            int n = q.size();
            while(n--)
            {
                std::pair<TreeNode* , long long> it = q.front();
                q.pop();

                long long idx = it.second - start;
                idx *= 2;

                if(it.first->left)
                {
                    q.push({it.first->left, idx + 1});
                }
                if(it.first->right)
                {
                    q.push({it.first->right, idx + 2});
                }
            }
        }
        return res;
    }
};

int main()
{
    return 0;
}