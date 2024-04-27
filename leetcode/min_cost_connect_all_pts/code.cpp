#include <iostream>
#include <assert.h>

#include <vector>
#include <queue>
#include <algorithm>

class Solution {
public:
    int minCostConnectPoints(std::vector<std::vector<int>>& points) {
        std::ios::sync_with_stdio(0);
        int n = points.size();
        std::vector<bool> visited(n, false);
        int res = 0;

        int connected = 0;
        std::priority_queue<std::pair<int, int>, 
                std::vector<std::pair<int, int>>, 
                std::greater<std::pair<int, int>>> pq;
        int i = 0;

        while(++connected < n)
        {
            visited[i] = true;

            for(int j = 0; j < n; j++)
            {
                if(!visited[j])
                {
                    int dist = std::abs(points[i][0] - points[j][0]) + 
                                std::abs(points[i][1] - points[j][1]);
                    pq.push({dist, j});
                }
            }

            while(visited[pq.top().second])pq.pop();

            res += pq.top().first;
            i = pq.top().second;
            pq.pop();
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<std::vector<int>> points = {{0,0},{2,2},
                                                {3,10},{5,2},{7,0}};
        int res = 20;
        assert(sol.minCostConnectPoints(points) == res);
    }
    return 0;
}