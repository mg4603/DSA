# Prims Algorithm

* A greedy algorithm used to find the minimum spanning tree of a undirected,  
connected graph with weighted edges.  
* Start with a single vertex and incrementally add the vertices that have the  
smallest edge connecting it to the existing MST

## Algorithm
    1. Choose the starting vertex(any vertex in the graph).
    2. Create a priority-queue of edges that connect the chosen vertex to it's 
        neighbors.
    3. Maintain a set of visited vertices 
    4. While the priority queue is not empty
        4.1 Remove the edge with the smallest weight from the priority-queue
        4.2 If both are in the visited vertices set, discard the edge
        4.3 Else add the edge to the MST and update the priority-queue with 
            edges connecting the newly added vertex to it's vertices
    5. Repeat step 4 until all the vertices are in the MST set

