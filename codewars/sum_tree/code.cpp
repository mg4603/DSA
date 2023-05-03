#include <assert.h>
#include <iostream>

struct node{
    int value;
    node *left;
    node *right;
};

int sumTheTreeValues(node* root) {
    if(root == nullptr){
        return 0;
    }
    return root->value + sumTheTreeValues(root->left) + sumTheTreeValues(root->right);
}

void testEasy()
{
    node easyNode = {10, new node {1, nullptr, nullptr}, new node {2, nullptr, nullptr}};
    assert(sumTheTreeValues(&easyNode) == 13);
}

void testUnbalanced()
{
    node unbalancedNode = {11, new node {0, nullptr, nullptr}, new node {0, nullptr, new node {1, nullptr, nullptr}}};
    assert(sumTheTreeValues(&unbalancedNode) == 12);
}

int main()
{
    testEasy();
    testUnbalanced();
    return 0;
}