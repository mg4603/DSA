# Graphs
- A collection of nodes with edges between(some of) them.
- Tree are connected acyclic graphs
- Properties:
    - Can be directed or undirected
    - Can have cycles
    - Can consist of unconnected sub-graphs
- A graphs where all nodes have a path between them is called a connected graph

## Representation
### Adjacency List
- A wrapper class containing references to all nodes is required as it is not 
necessarily possible to reach every node from a single node(root).
```
class Node{
    <datatype> data;
    vector<Node*> children;
}

class Graph{
    vector<Node*> nodes;
}
```

### Adjacency Matrices
- NxN boolean matrix(N nodes) where true value of matrix\[i\]\[j\] represents 
an edge from node i to node j
- symmetric in undirected graph
- not necessarily in directed graph

