#include <iostream>

#include <map>
#include <vector>
#include <queue>
#include <limits>

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

struct DistanceComparator
{
    bool operator()(const std::pair<char, int> &a, const std::pair<char, int> &b)
    {
        return a.second > b.second;
    }
};

using DistanceQueue = std::priority_queue<std::pair<char, int>,
             std::vector<std::pair<char, int>>, DistanceComparator>;

std::map<char, int> djikstra(std::map<char, std::vector<Edge>> &graph,
                     char source_node)
{
    DistanceQueue pq;
    pq.push(std::make_pair(source_node, 0));

    std::map<char, int> shortest_distances;
    for(auto node: graph)
    {
        shortest_distances[node.first] = std::numeric_limits<int>::max();
    }

    shortest_distances[source_node] = 0;

    while(!pq.empty())
    {
        std::pair<char, int> current_node = pq.top();
        pq.pop();
        if(current_node.second > shortest_distances[current_node.first])
        {
            continue;
        }

        for(Edge edge: graph[current_node.first])
        {
            int distance(current_node.second + edge.weight);
            if(distance < shortest_distances[edge.vertex2])
            {
                shortest_distances[edge.vertex2] = distance;
                pq.push(std::make_pair(edge.vertex2, distance));
            }
        }
    }

    return shortest_distances;
}

int main()
{

    std::map<char, std::vector<Edge>> graph = {
        {'A', std::vector<Edge>{Edge('A', 'B', 1), Edge('A', 'C', 4)}},
        {'B', std::vector<Edge>{Edge('B', 'A', 1), Edge('B', 'C', 2),
                                 Edge('B', 'D', 5)}},
        {'C', std::vector<Edge>{Edge('C', 'A', 4), Edge('C', 'B', 2),
                                 Edge('C', 'D', 1)}},
        {'D', std::vector<Edge>{Edge('D', 'B', 5), Edge('D', 'C', 1)}},
    };

    char source_node = 'A';
    std::map<char, int> shortest_distances = djikstra(graph, source_node);
    std::cout << "Shortest distance from source node "<< source_node << ":\n";
    for(auto shortest_distance: shortest_distances)
    {
        std::cout << shortest_distance.first << " : " << shortest_distance.second
                 << std::endl;
    }


    return 0;
}