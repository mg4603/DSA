#include <iostream>
#include <assert.h>

#include <vector>
#include <queue>

class Node {
public:
    int val;
    std::vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, std::vector<Node*> _children) 
    {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    std::vector<std::vector<int>> levelOrder(Node* root) 
    {
        if(root == nullptr)
        {
            return {};
        }
        std::queue<Node*> q;
        q.push(root);

        std::vector<std::vector<int>> res;

        int h = 0;
        while(!q.empty())
        {
            int n = q.size();
            res.push_back({});
            while(n-- > 0)
            {
                Node *curr = q.front();
                q.pop();
                res[h].push_back(curr->val);

                for(auto it: curr->children)
                {
                    q.push(it);
                }
            }
            h++;
        }    
        return res;
    }
};

int main()
{
    return 0;
}