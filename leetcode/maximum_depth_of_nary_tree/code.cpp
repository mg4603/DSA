#include <iostream>
#include <assert.h>

#include <vector>

class Node {
public:
    int val;
    std::vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, std::vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    int maxDepth(Node* root) {
        if(root == nullptr)
        {
            return 0;
        }
        int max_depth(0);
        for(Node* node: root->children)
        {
            max_depth = std::max(max_depth, maxDepth(node));
        }
        return 1 + max_depth;
    }
};

int main()
{
    Solution sol;
    {
        Node *seven = new Node(7);
        Node *eleven = new Node(11);
        Node *fourteen = new Node(14);
        Node *six = new Node(6);
        Node *three = new Node(3);

        eleven->children.push_back(fourteen);
        seven->children.push_back(eleven);
        three->children.push_back(six);
        three->children.push_back(seven);

        Node *twelve = new Node(12);
        Node *eight = new Node(8);
        Node *four = new Node(4);
        eight->children.push_back(twelve);
        four->children.push_back(eight);

        Node *thirteen = new Node(13);
        Node *nine = new Node(9);

        Node *ten = new Node(10);

        Node *five = new Node(5);
        five->children.push_back(ten);
        five->children.push_back(nine);

        Node *two = new Node(2);

        Node *one = new Node(1);

        one->children.push_back(two);
        one->children.push_back(three);
        one->children.push_back(four);
        one->children.push_back(five);

        assert(sol.maxDepth(one) == 5);
    }
    {
        Node *one = new Node(1);
        Node *two = new Node(2);
        Node *three = new Node(3);        
        Node *four = new Node(4);
        Node *five = new Node(5);
        Node *six = new Node(6);

        three->children.push_back(five);
        three->children.push_back(six);

        one->children.push_back(two);
        one->children.push_back(three);
        one->children.push_back(four);

        assert(sol.maxDepth(one) == 3);
    }
    return 0;
}