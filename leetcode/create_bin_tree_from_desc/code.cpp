#include <iostream>
#include <assert.h>

#include <unordered_map>
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
    TreeNode* createBinaryTree(
                std::vector<std::vector<int>>& descriptions) {
        std::unordered_map<int, TreeNode*> nodes;
        std::unordered_map<int, bool> isChild;

        for(std::vector<int> &desc: descriptions) {
            if(!nodes.count(desc[0])) {
                nodes[desc[0]] = new TreeNode(desc[0]);
                isChild[desc[0]] = 0;
            }
            if(!nodes.count(desc[1])) {
                nodes[desc[1]] = new TreeNode(desc[1]);
            }
            if(desc[2] == 1) {
                nodes[desc[0]]->left = nodes[desc[1]];
            }else {
                nodes[desc[0]]->right = nodes[desc[1]];
            }
            isChild[desc[1]] = 1;
        }
        TreeNode *root;
        for(auto child: isChild) {
            if(child.second == 0) {
                root = nodes[child.first];
                break;
            }
        }
        return root;
    }
};

int main()
{
    return 0;
}