#include <iostream>
#include <assert.h>

#include <map>
#include <vector>
#include <queue>

class Node {
public:
    int val;
    std::vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = std::vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = std::vector<Node*>();
    }
    Node(int _val, std::vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    Node* cloneGraph(Node* node) 
    {
        if(node == nullptr)
        {
            return nullptr;
        }

        std::queue<Node*> q;
        q.push(node);

        Node *res;
        std::map<Node*, Node*> mp;

        while(!q.empty())
        {
            Node *curr = q.front();
            q.pop();

            if(mp.find(curr) == mp.end())
            {
                mp[curr] = new Node(curr->val);
            }

            for(auto ptr: curr->neighbors)
            {
                if(mp.find(ptr) == mp.end())
                {
                    mp[ptr] = new Node(ptr->val);
                    q.push(ptr);
                }
                mp[curr]->neighbors.push_back(mp[ptr]);
            }
        }    
        return mp[node];
    }
};

int main()
{
    return 0;
}