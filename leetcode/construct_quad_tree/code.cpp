#include <iostream>
#include <assert.h>

#include <vector>

class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, 
         Node* _topRight, Node* _bottomLeft, 
         Node* _bottomRight) 
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
    Node *buildTree(std::vector<std::vector<int>> & grid, 
                    int i, int j, int n)
    {
        if(n == 1)
        {
            return new Node(grid[i][j], true);
        }

        Node *res = new Node(grid[i][j], false,
                        buildTree(grid, i, j, n/2),
                        buildTree(grid, i, j + n/2, n/2),
                        buildTree(grid, i + n/2, j, n/2),
                        buildTree(grid, i + n/2, j + n/2, n/2));

        int val = res->topLeft->val;
        if(res->topLeft->isLeaf && 
            res->topRight->isLeaf && 
            res->bottomLeft->isLeaf && 
            res->bottomRight->isLeaf && 
            res->topRight->val == val &&
            res->bottomLeft->val == val &&
            res->bottomRight->val == val
            )
        {
            res->isLeaf = true;
            res->val = val;
            delete res->topLeft;
            delete res->topRight;
            delete res->bottomLeft;
            delete res->bottomRight;

            res->topLeft = nullptr;
            res->topRight = nullptr;
            res->bottomLeft = nullptr;
            res->bottomRight = nullptr;
        }
        return res;
    }
public:
    Node* construct(std::vector<std::vector<int>>& grid) 
    {
        int n = grid.size();
        return buildTree(grid, 0, 0, n);
    }   
};

int main()
{
    return 0;
}