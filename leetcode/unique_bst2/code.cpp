#include <iostream>
#include <assert.h>

#include <vector>


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    std::vector<TreeNode*> createTree(int a, int b)
    {
        TreeNode *root;
        std::vector<TreeNode*> left;
        std::vector<TreeNode*> right;
        std::vector<TreeNode*> result;

        if(a > b)
        {
            result.push_back(nullptr);
        }
        else if(a == b)
        {
            root = new TreeNode(a);
            result.push_back(root);
        }
        else
        {
            for(int i = a; i <= b; i++)
            {
                left = createTree(a, i - 1);
                right = createTree(i + 1, b);
                for(auto l = left.begin(); l < left.end(); l++)
                {
                    for(auto r = right.begin(); r < right.end(); r++)
                    {
                        root = new TreeNode(i, *l, *r);
                        result.push_back(root);
                    }
                }
            }
        }
        return result;

    }
public:
    std::vector<TreeNode*> generateTrees(int n) {
        return createTree(1, n);
    }
};

int main()
{
    return 0;
}