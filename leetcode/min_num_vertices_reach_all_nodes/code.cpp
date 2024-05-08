#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    std::vector<int> findSmallestSetOfVertices(int n, 
                    std::vector<std::vector<int>>& edges) {
        std::ios::sync_with_stdio(0);
        std::vector<int> incoming(n);
        for(int i = 0; i < edges.size(); i++)
        {
            incoming[edges[i][1]]++;
        }

        std::vector<int> res;
        for(int i = 0; i < n; i++)
        {
            if(incoming[i] == 0)res.push_back(i);
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        int n = 6;
        std::vector<std::vector<int>> edges = {{0,1},{0,2},{2,5},
                                               {3,4},{4,2}};
        std::vector<int> res = {0, 3};
        assert(sol.findSmallestSetOfVertices(n, edges) == res);
    }
    return 0;
}