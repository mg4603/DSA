# TREE
## Intro
- Each tree has a root node
- A root node has zero or more child nodes
- Each child node has zero or more child nodes
- A node without any children is called a leaf node
- Properties:
    - No cycles
    - may or may not be in a particular order
    - can have any data type as values
    - may or may not have links back to parent nodes

### Node Definition
```
class Node{
    <datatype> data;
    Node[] children;
}
```
### Tree wrapper
```
class Tree{
    Node root;
}
``` 
## Types of trees
### Trees vs. Binary Trees
- Binary trees have up to two children
- Not all trees are binary tree and can have any number of children

### Binary Search Trees
- Follow the rule:
```
all descendants on the left <= root < all descendants on the right
```
- Position of equal elements can vary depending on implementation:
    - left
    - right
    - may be prevented from having duplicates

### Balanced Tree
- Doesn't mean that all left subtrees are the same size as right subtrees
- Refers to trees where the insert and find time for elements is O(log n)
- Types:
    - AVL
    - Red-black trees


### Complete Binary Tree
- Binary Tree in which every level is fully filled except the last level
- Last level is filled from left to right

### Full Binary Tree
- Binary tree in which all nodes have zero or two children
- No node has only one child

### Perfect Binary Tree
- Binary tree that is full and complete.
- Must have exactly (2^k - 1) nodes.

## Binary Tree Traversal
### In-order 
- visit the left branch, then the current node and lastly the right branch recursively
```
void inOrderTraversal(Node *n){
    if(n != null){
        inOrderTraversal(n->left);
        visit(n);
        inOrderTraversal(n->right);
    }
}
```
### Pre-order
- visit the current node first, then the left branch and lastly the right branch recursively
```
void preOrderTraversal(Node *n){
    if(n != null){
        visit(n);
        preOrderTraversal(n->left);
        preOrderTraversal(n->right);
    }
}
```
### Post-order
- visit the left branch first, then the right branch and finally the current node
```
void postOrderTraversal(Node *n){
    if(n != null){
        postOrderTraversal(n->left);
        postOrderTraversal(n->right);
        visit(n);
    }
}
```
