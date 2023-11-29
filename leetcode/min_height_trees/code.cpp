#include <iostream>
#include <assert.h>

#include <vector>
#include <queue>

class Solution {
public:
    std::vector<int> findMinHeightTrees(int n, 
                            std::vector<std::vector<int>>& edges) 
    {
        if(n == 0)
        {
            return {};
        }
        if(n == 1)
        {
            return {0};
        }

        std::vector<int> indegree(n, 0);
        std::vector<std::vector<int>> adj(n);

        for(int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];

            indegree[u]++;
            indegree[v]++;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        std::queue<int> q;

        for(int i = 0; i < n; i++)
        {
            if(indegree[i] == 1)
            {
                q.push(i);
            }
        }

        std::vector<int> res;
        
        while(!q.empty())
        {
            res.clear();
            int size = q.size();
            for(int i = 0; i < size; i++)
            {
                int curr = q.front();
                q.pop();
                res.push_back(curr);

                for(int j = 0; j < adj[curr].size(); j++)
                {
                    int temp = --indegree[adj[curr][j]];
                    if(temp == 1)
                    {
                        q.push(adj[curr][j]);
                    }
                }
            }
        }

        return res;
    }
};

int main()
{
    Solution sol;
    {
        int n = 4;
        std::vector<std::vector<int>> edges = {{1,0},{1,2},{1,3}};
        std::vector<int> res = {1};
        assert(sol.findMinHeightTrees(n, edges) == res);
    }
    {
        int n = 6;
        std::vector<std::vector<int>> edges = {{3,0},{3,1},
                                               {3,2},{3,4},{5,4}};
        std::vector<int> res = {3,4};
        assert(sol.findMinHeightTrees(n, edges) == res);
    }
    return 0;
}