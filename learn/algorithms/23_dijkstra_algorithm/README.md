# Djikstra's Algorithm

* Algorithm to find the shortest path between a source node and all other nodes  
in a weighted graph
* Works as long as graph doesn't contain cycles with negative total weights.

## Algorithm

    1. Mark all nodes as unvisited and and set the initial distance of the 
        source node to 0. Set the distance to all other to infinity.
    2. Choose the unvisited node with smallest distance as current node
    3. Calculate the tentative distance to all neighbors of the current node
        through it. If the tentative distance is smaller than the current  
        assigned distance, update the distance.
    4. Mark the node as visited after all it's neighbors have been explored and
        don't visit it again.
    5. Repeat steps 2 to 4 until all nodes have been visited.
    6. Reconstruct the shortest path from destination to source using recorded 
        previous nodes.

### Notes:
* Use Bellman-Ford algorithm if graph contains negative weight edges
* Djikstra's algorithm is not optimal for graphs with a large number of nodes  
    (use more advanced algorithms like A-star)
* Floyd-Warshall algorithm is more suitable for finding the shortest path between  
every node.