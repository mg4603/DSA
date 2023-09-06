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
    void postorder(Node *root, std::vector<int> &vec)
    {
        if(root == nullptr)
        {
            return;
        }
        for(Node *child: root->children)
        {
            postorder(child, vec);
        }
        vec.push_back(root->val);
    }
public:
    std::vector<int> postorder(Node* root) {
        std::vector<int> res;
        postorder(root, res);
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

        std::vector<int> res({5,6,3,2,4,1});
        assert(sol.postorder(one) == res);
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

        nine->children.push_back(thirteen);

        three->children.push_back(six);
        three->children.push_back(seven);

        four->children.push_back(eight);

        five->children.push_back(nine);
        five->children.push_back(ten);

        one->children.push_back(two);
        one->children.push_back(three);
        one->children.push_back(four);
        one->children.push_back(five);

        std::vector<int> res({2,6,14,11,7,3,12,8,4,13,9,10,5,1});
        assert(sol.postorder(one) == res);
    }
    return 0;
}