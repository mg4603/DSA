#include <iostream>
#include <assert.h>

#include <vector>
#include <unordered_map>

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
    std::vector<TreeNode*> helper(int n, 
                        std::unordered_map<int, 
                            std::vector<TreeNode *>> &memo)
    {
        std::vector<TreeNode *> ans;
        if(n < 1 || n % 2 == 0)
        {
            return ans;
        }

        if(memo.count(n))
        {
            return memo[n];
        }

        if(n == 1)
        {
            ans.push_back(new TreeNode(0));
            memo[1] = ans;
            return ans;
        }

        for(int i = 1; i < n; i += 2)
        {
            std::vector<TreeNode*> left = helper(i, memo);
            std::vector<TreeNode*> right = helper(n - 1 - i, memo);

            for(int j = 0; j < left.size(); j++)
            {
                for(int k = 0; k < right.size(); k++)
                {
                    TreeNode *root = new TreeNode(0);
                    root->left = left[j];
                    root->right = right[k];
                    ans.push_back(root);
                }
            }
        }
        memo[n] = ans;
        return ans;
    }
public:
    std::vector<TreeNode*> allPossibleFBT(int n) {
        std::unordered_map<int, std::vector<TreeNode*>> memo;
        return helper(n, memo);
    }
};

int main()
{
    return 0;
}