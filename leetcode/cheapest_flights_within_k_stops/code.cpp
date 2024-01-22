#include <iostream>
#include <assert.h>

#include <unordered_map>
#include <vector>
#include <queue>
#include <climits>

class Solution {
public:
    int findCheapestPrice(int n, 
                        std::vector<std::vector<int>>& flights, 
                        int src, int dst, int k)
    {
        std::unordered_map<int, 
                std::vector<
                    std::pair<int, int>>> graph;
        std::vector<int> min_dist(n, INT_MAX);

        for(int i = 0; i < flights.size(); i++)
        {
            graph[flights[i][0]].push_back({flights[i][1], 
                                            flights[i][2]});
        }

        std::queue<std::pair<int,int>> q;
        q.push({src, 0});
        int stops = 0;

        while(!q.empty() && stops <= k)
        {
            int size = q.size();
            while(size--)
            {
                std::pair<int, int> it = q.front();
                q.pop();
                for(std::pair<int, int> it1: graph[it.first])
                {
                    int new_dist = it1.second + it.second;
                    if(new_dist < min_dist[it1.first])
                    {
                        min_dist[it1.first] = new_dist;
                        q.push({it1.first, min_dist[it1.first]});
                    }
                }
            }
            stops++;
        }

        if(min_dist[dst] == INT_MAX)
        {
            return -1;
        }
        return min_dist[dst];
    }
};

int main()
{
    Solution sol;
    {
        int n = 4;
        std::vector<std::vector<int>> flights = {{0,1,100},{1,2,100},
                                                 {2,0,100},{1,3,600},
                                                 {2,3,200}};
        int src = 0;
        int dst = 3;
        int k = 1;
        int res = 700;
        assert(sol.findCheapestPrice(n, flights, src, dst, k) == res);
    }
    return 0;
}