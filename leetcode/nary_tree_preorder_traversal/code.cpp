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
    void preorder(Node *root, std::vector<int> &vec)
    {
        if(root == nullptr)
        {
            return;
        }
        vec.push_back(root->val);
        for(Node *child: root->children)
        {
            preorder(child, vec);
        }

    }
public:
    std::vector<int> preorder(Node* root) {
        std::vector<int> res;
        preorder(root, res);
        return res;
    }
};

int main()
{
    Solution sol;
    {
        Node *one = new Node(1);
        Node *two = new Node(2);
        Node *three = new Node(3);
        Node *four = new Node(4);
        Node *five = new Node(5);
        Node *six = new Node(6);

        three->children.push_back(five);
        three->children.push_back(six);

        one->children.push_back(three);
        one->children.push_back(two);
        one->children.push_back(four);

        assert(sol.preorder(one) == std::vector<int>({1,3,5,6,2,4}));
    }
    {
        Node *one = new Node(1);
        Node *two = new Node(2);
        Node *three = new Node(3);
        Node *four = new Node(4);
        Node *five = new Node(5);
        Node *six = new Node(6);
        Node *seven = new Node(7);
        Node *eight = new Node(8);
        Node *nine = new Node(9);
        Node *ten = new Node(10);
        Node *eleven = new Node(11);
        Node *twelve = new Node(12);
        Node *thirteen = new Node(13);
        Node *fourteen = new Node(14);

        eleven->children.push_back(fourteen);
        seven->children.push_back(eleven);

        eight->children.push_back(twelve);
        four->children.push_back(eight);

        nine->children.push_back(thirteen);

        five->children.push_back(nine);
        five->children.push_back(ten);

        three->children.push_back(six);
        three->children.push_back(seven);

        one->children.push_back(two);
        one->children.push_back(three);
        one->children.push_back(four);
        one->children.push_back(five);

        assert(sol.preorder(one) == std::vector<int>({1,2,3,6,7,11,14,4,8,12,5,9,13,10}));
    }
    return 0;
}