# Kruskal's Algorithm

* Greedy algorithm to find the minimum spanning tree of a connected, undirected  
graph with weighted edges.
* Sort the edges and iteratively add the smallest edge as long as it doesn't  
create a cycle.

## Algorithm
    1. Sort the edges in ascending order of weight
    2. Create n sets each containing one vertex
    3. Iterate through the edges
        3.1 If the two vertices of the edge are in different sets, add the edge 
            to the MST and merge the sets.
        3.2 If the two vertices are in the same set, skip the edge to avoid 
            creating a cycle
    4. Repeat step 3 until the MST contains (V - 1) edges where V is the number 
        of vertices in the original graph

