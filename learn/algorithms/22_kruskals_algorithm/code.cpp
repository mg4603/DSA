#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

struct Edge
{
    char vertex1;
    char vertex2;
    int weight;
    Edge()
    {

    }
    Edge(char vertex1, char vertex2, int weight)
    {
        this->vertex1 = vertex1;
        this->vertex2 = vertex2;
        this->weight = weight;
    }
};

bool edge_comparator(Edge &a, Edge &b)
{
    return a.weight < b.weight;
}

class UnionFind{
    std::map<char, char> parent;
    std::map<char, int> rank;
    public:
        UnionFind(std::vector<char> &vertices)
        {
            for(char vertex: vertices)
            {
                parent[vertex] = vertex;
                rank[vertex] = 0;
            }
        }
        char find(char vertex)
        {
            if(this->parent[vertex] != vertex)
            {
                this->parent[vertex] = this->find(this->parent[vertex]);
            }
            return this->parent[vertex];
        }

        void tree_union(char vertex1, char vertex2)
        {
            char root_x = this->find(vertex1);
            char root_y = this->find(vertex2);
            if(root_x == root_y)
            {
                return;
            }
            if(this->rank[root_x] < this->rank[root_y])
            {
                this->parent[root_x] = root_y;
                this->rank[root_y]++;
            }
            else
            {
                this->parent[root_y] = root_x;
                this->rank[root_x]++;
            }
        }

};

std::vector<Edge> kruskals_mst(std::map<char, std::vector<Edge>> &graph)
{
    std::vector<Edge> edges;
    std::vector<char> vertices;
    for(auto vertex: graph)
    {   
        vertices.push_back(vertex.first);
        for(auto edge: vertex.second)
        {
            edges.push_back(edge);
        }
    }

    std::sort(edges.begin(), edges.end(), edge_comparator);

    std::vector<Edge> mst;
    int num_vertices = graph.size();

    UnionFind uf(vertices);

    for(auto edge: edges)
    {
        if(uf.find(edge.vertex1) != uf.find(edge.vertex2))
        {
            uf.tree_union(edge.vertex1, edge.vertex2);
            mst.push_back(edge);
        }
        if(mst.size() == num_vertices - 1)
        {
            break;
        }
    }
    return mst;
}


int main()
{

    std::map<char, std::vector<Edge>> graph = {
        {'A', std::vector<Edge>{Edge('A', 'B', 2), Edge('A', 'D', 3)}},
        {'B', std::vector<Edge>{Edge('B', 'A', 2), Edge('B', 'C', 1), Edge('B', 'D', 4)}},
        {'C', std::vector<Edge>{Edge('C', 'B', 1), Edge('C', 'D', 5)}},
        {'D', std::vector<Edge>{Edge('D', 'A', 3), Edge('D', 'B', 4), Edge('D', 'C', 5)}},
    };
    std::vector<Edge> mst = kruskals_mst(graph);
    std::cout << "Kruskal's MST:\n";
    for(auto edge: mst)
    {
        std::cout << edge.vertex1 << "-" << edge.vertex2 << " : " << edge.weight << std::endl;
    }
    return 0;
}