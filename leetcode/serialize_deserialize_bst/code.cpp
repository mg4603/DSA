#include <iostream>
#include <assert.h>

#include <sstream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
    void encode(TreeNode *n, std::string &res)
    {
        if(!n)return;

        res += std::to_string(n->val) + ",";
        encode(n->left, res);
        encode(n->right, res);
    }

    TreeNode *decode(TreeNode *n, int val)
    {
        if(!n)
        {
            n = new TreeNode(val);
            return n;
        }

        if(val <= n->val)
        {
            n->left = decode(n->left, val);
        }
        else
        {
            n->right = decode(n->right, val);
        }
        return n;
    }
public:

    std::string serialize(TreeNode* root) 
    {
        std::string res;
        encode(root, res);
        return res; 
    }

    TreeNode* deserialize(std::string data) 
    {
        std::stringstream ss(data);
        std::string temp;
        TreeNode *root = nullptr;
        while(getline(ss, temp, ','))
        {
            root = decode(root, std::stoi(temp));
        }
        return root;
    }
};

int main()
{
    return 0;
}