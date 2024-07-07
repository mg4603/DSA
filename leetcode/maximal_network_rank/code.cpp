#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    int maximalNetworkRank(int n, std::vector<std::vector<int>>& roads) {
        std::ios::sync_with_stdio(0);
        std::vector<int> count(n);
        std::vector<std::vector<int>> connected(n, 
                                std::vector<int>(n, 0));
        
        for(auto &road: roads) {
            count[road[0]]++;
            count[road[1]]++;

            connected[road[0]][road[1]] = 1;
            connected[road[1]][road[0]] = 1;
        }

        int res = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                int temp = count[i] + count[j] - connected[i][j];
                res = std::max(res, temp);
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
        std::vector<std::vector<int>> roads = {{0,1},{0,3},
                                               {1,2},{1,3}};
        int res = 4;
        assert(sol.maximalNetworkRank(n, roads) == res);
    }
    return 0;
}