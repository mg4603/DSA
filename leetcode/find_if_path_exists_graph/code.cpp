#include <iostream>
#include <assert.h>

#include <vector>

class DisjointSet
{
    std::vector<int> parent;
    std::vector<int> sizes;
    public:
        DisjointSet(int n)
        {
            parent = std::vector<int>(n + 1, 0);
            sizes = std::vector<int>(n + 1, 1);
            for(int i = 0; i < n + 1; i++)
            {
                parent[i] = i;
            }
        }

        int findParent(int node)
        {
            if(node == parent[node])
            {
                return node;
            }
            return findParent(parent[node]);
        }

        void setUnion(int u, int v)
        {
            int parent_u = findParent(u);
            int parent_v = findParent(v);
            if(parent_u == parent_v)
            {
                return;
            }
            if(sizes[parent_u] < sizes[parent_v])
            {
                parent[parent_u] = parent_v;
                sizes[parent_v] += sizes[parent_u];
            }
            else
            {
                parent[parent_v] = parent_u;
                sizes[parent_u] += sizes[parent_v];
            }
        }
};
class Solution {
public:
    bool validPath(int n, std::vector<std::vector<int>>& edges, 
                    int source, int destination) 
    {
           DisjointSet ds(n);
           for(int i = 0; i < edges.size(); i++)
           {
               ds.setUnion(edges[i][0], edges[i][1]);
           }
           return ds.findParent(source) == ds.findParent(destination);
    }
};

int main()
{
    Solution sol;
    {
        int n = 3;
        std::vector<std::vector<int>> edges = {
            {0,1},{1,2},{2,0}};
        int source = 0;
        int destination = 2;
        int res = true;
        assert(sol.validPath(n, edges, source, destination) == res);
    }
    {
        int n = 6;
        std::vector<std::vector<int>> edges = {
            {0,1},{0,2},{3,5},{5,4},{4,3}};
        int source = 0;
        int destination = 5;
        int res = false;
        assert(sol.validPath(n, edges, source, destination) == res);
    }
    return 0;
}