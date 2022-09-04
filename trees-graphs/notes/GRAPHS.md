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

# Graph Search
- Must check if node has already been visited in a graph
    - Cyclic graphs can cause infinite loop if such a check is not done
## DFS
- Preferred when visiting every node in the graph
- Tree traversal(pre, post, in - order) are forms of DFS
- Process:
    - Start at the root or an arbitrarily selected node
    - Explore each branch completely
    - Do the same for the next branch
```
void search(Node root){
    if(root == null){
        return;
    }
    visit(root);
    root.visited = true;
    for(Node n : adjacentNodes){
        if(!n.visited){
            search(n);
        }
    }
}
```
## BFS
- Useful when you want to find the shortest path between two nodes
- Process:
    - Start at the root or an arbitrarily selected node
    - explore each neighbor
    - Move on to the next level
```
void search(Node root){
    queue<Node*> queue;
    root.visited = true;
    queue.push(root);

    while(!queue.isEmpty()){
        Node* current = queue.front();
        queue.pop();
        visit(n);
        for(Node* n: current.adjacent){
            if(!n.visited){
                visit(n);
                queue.push(n);
            }
        }
    }
}
```
## Bi-directional search
- Used to find the shortest path between two nodes
    - Run two simultaneous breadth-first searches, one from each node
    - When searches collide, a path has been found
- Traditional BFS takes O(k^d) where k is the number of adjacent nodes at a level
    and d is the number of levels in between the two nodes
- Bi-directional search takes O(k^d/2) time for search from both nodes
    which is lesser by a factor of k^d/2