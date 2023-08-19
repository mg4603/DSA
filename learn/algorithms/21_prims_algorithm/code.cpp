#include <iostream>

#include <vector>
#include <queue>
#include <set>
#include <map>

struct Edge
{
    char vertex1;
    char vertex2;
    int weight;
    Edge(char vertex1, char vertex2, int weight)
    {
        this->vertex1 = vertex1;
        this->vertex2 = vertex2;
        this->weight = weight;
    }
};

struct EdgeComparator
{
    bool operator()(const Edge a, const Edge b)
    {
        return a.weight > b.weight;
    }
};

using EdgePriorityQueue = std::priority_queue<Edge, std::vector<Edge>, EdgeComparator>;

std::vector<Edge> prim_mst(std::map<char, std::vector<Edge>> &graph)
{
    std::vector<Edge> mst;
    std::set<char> visited_vertices;

    char start_vertex(graph.begin()->first);
    EdgePriorityQueue pq(graph[start_vertex].begin(), graph[start_vertex].end());

    visited_vertices.insert(start_vertex);
    while(!pq.empty())
    {
        Edge top = pq.top();
        pq.pop();

        if(visited_vertices.find(top.vertex2) != visited_vertices.end() && 
            visited_vertices.find(top.vertex1) != visited_vertices.end())
        {
            continue;
        }

        mst.push_back(top);
        
        for(Edge edge: graph[top.vertex2])
        {
            if(visited_vertices.find(edge.vertex2) == visited_vertices.end())
            {
                pq.push(edge);
            }
        }
        
        visited_vertices.insert(top.vertex2);
        
    }

    return mst;
}

int main()
{
    std::map<char, std::vector<Edge>> graph{
        {'A', std::vector<Edge>{Edge('A', 'B', 2), Edge('A', 'D', 3)}},
        {'B', std::vector<Edge>{Edge('B', 'A', 2), Edge('B', 'C', 1), Edge('B', 'D', 4)}},
        {'C', std::vector<Edge>{Edge('C', 'B', 1), Edge('C', 'D', 5)}},
        {'D', std::vector<Edge>{Edge('D', 'A', 3), Edge('D', 'B', 4), Edge('D', 'C', 5)}},
    };

    std::vector<Edge> mst = prim_mst(graph);
    std::cout << "Minimum Spanning tree:\n";
    for(Edge edge: mst)
    {
        std::cout << edge.vertex1 << ' ' << edge.vertex2 << " : " << edge.weight << std::endl; 
    }
    return 0;
}