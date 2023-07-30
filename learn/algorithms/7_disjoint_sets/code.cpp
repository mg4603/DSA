#include <iostream>
#include <vector>


int get_parent(std::vector<int> &vec, int vertex)
{
    while(true)
    {
        if(vec[vertex] < 0)
        {
            break;
        }
        else
        {
            vertex = vec[vertex];
        }
    }
    return vertex;
}

// return true if already part of the same set
bool set_union(std::vector<int> &vec, int vertex1, int vertex2)
{
    int parent1 = get_parent(vec, vertex1);
    int parent2 = get_parent(vec, vertex2);

    if(parent1 == parent2)
    {
        return true;
    }
    int new_rank = vec[parent1] + vec[parent2];
    if(vec[parent1] < vec[parent2])
    {
        vec[parent2] = parent1;
        vec[parent1] = new_rank;
    }
    else
    {
        vec[parent1] = parent2;
        vec[parent2] = new_rank;
    }
    return false;
}

/*
1-3
| |
2-4
|
5-7
| |
6-8
*/

int main()
{
    // each edge is denoted by an array idex
    // root of each tree is denoted by rank of tree(-ve of number of nodes in tree)
    std::vector<int> vertices(8, -1);
    std::vector<std::pair<int, int>> edges{{1, 2}, {1, 3}, {3, 4}, {2, 4}, {2, 5}, 
                                        {5, 7}, {5, 6}, {7, 8}, {6, 8}};
    
    for(std::pair<int, int> edge: edges)
    {
        if(set_union(vertices, edge.first, edge.second))
        {
            std::cout << "Cycle found while trying to join: " << edge.first 
                        << " " << edge.second << "." << std::endl;
        }
    }
    return 0;
}