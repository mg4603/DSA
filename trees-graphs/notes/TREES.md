# TREE
## Intro
- Each tree has a root node
- A root node has zero or more child nodes
- Each child node has zero or more child nodes
- Properties:
    - No cycles
    - may or may not be in a particular order
    - can have any data type as values
    - may or may not have links back to parent nodes

## Node Definition
```
class Node{
    <datatype> data;
    Node[] children;
}
```
## Tree wrapper
```
class Tree{
    Node root;
}
``` 
### Trees vs. Binary Trees



