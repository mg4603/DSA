# Disjoint Sets
Sets s1 and s2 are disjoint iff $s1\cap s2 = \phi$
## Operations
1. Find:  
    * of which set is the element a member(set membership operation).
2. Union:
    * the union of two sets $s1\cup s2$ is a set that contains every unique  
    element in s1 and s2.

## Finding Cycle
1. Take all elements of graph to be singleton sets.
2. For every edge:
    1. Find which sets the vertices belongs to.
    2. If they belong to different sets perform union and repeat for the next edge
    3. Else there exists a cycle in the graph.

## Collapsing find
1. Set the parent of child nodes to root node when performing union.

