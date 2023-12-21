#include <iostream>
#include <assert.h>

class Node 
{
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() 
    {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) 
    {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, 
         Node* _topLeft, Node* _topRight, 
         Node* _bottomLeft, Node* _bottomRight) 
    {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

class Solution {
public:
    Node* intersect(Node* t1, Node* t2) 
    {
        if(t1->isLeaf && t1->val)return t1;
        if(t2->isLeaf && t2->val)return t2;
        if(t1->isLeaf && !t1->val)return t2;
        if(t2->isLeaf && !t2->val)return t1;

        Node *top_left = intersect(t1->topLeft, 
                                t2->topLeft);

        Node *top_right = intersect(t1->topRight, 
                                t2->topRight);

        Node *bottom_left = intersect(t1->bottomLeft, 
                                t2->bottomLeft);

        Node *bottom_right = intersect(t1->bottomRight, 
                                t2->bottomRight);


        int val = top_left->val;
        if(val == top_right->val && 
           val == bottom_left->val && 
           val == bottom_right->val && 
           top_left->isLeaf && 
           top_right->isLeaf && 
           bottom_left->isLeaf && 
           bottom_right->isLeaf)
        {
            return new Node(val, true);
        }
        return new Node(0, false, top_left, top_right,
                        bottom_left, bottom_right);
    }
};

int main()
{
    return 0;
}