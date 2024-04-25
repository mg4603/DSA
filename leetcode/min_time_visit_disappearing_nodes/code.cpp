#include <iostream>
#include <assert.h>

#include <vector>
#include <queue>
#include <limits>
#include <unordered_map>

class Solution {
public:
    std::vector<int> minimumTime(int n, 
                    std::vector<std::vector<int>>& edges, 
                    std::vector<int>& disappear) {

        std::ios::sync_with_stdio(0);
        std::vector<int> res(n, std::numeric_limits<int>::max());
        std::priority_queue<std::pair<int, int>, 
                        std::vector<std::pair<int, int>>, 
                        std::greater<std::pair<int, int>>> pq;
        res[0] = 0;
        // weight - node
        pq.push({0, 0});

        // node - weight
        std::unordered_map<int, std::vector<std::pair<int, int>>> graph;
        for(auto & edge: edges)
        {
            graph[edge[0]].push_back({edge[1], edge[2]});
            graph[edge[1]].push_back({edge[0], edge[2]});
        }

        while(!pq.empty())
        {
            auto [weight, u] = pq.top();
            pq.pop();

            if(weight >= disappear[u] || res[u] < weight)continue;

            for(auto [v, new_wt]: graph[u])
            {
                int curr = weight + new_wt;
                if(res[v] > curr && curr < disappear[v])
                {
                    res[v] = curr;
                    pq.push({res[v], v});
                }
            }
        }

        for(auto &wt: res)
        {
            if(wt == std::numeric_limits<int>::max())wt = -1;
        }

        return res;
    }
};

int main()
{
    Solution sol;
    {
        int n = 3;
        std::vector<std::vector<int>> edges = {{0,1,2},
                                               {1,2,1},
                                               {0,2,4}};
        std::vector<int> disappear = {1,1,5};
        std::vector<int> res = {0,-1,4};
        assert(sol.minimumTime(n, edges, disappear) == res);
    }
    return 0;
}