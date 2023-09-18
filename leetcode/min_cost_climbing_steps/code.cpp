#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    int minCostClimbingStairs(std::vector<int>& cost) {
        int n = cost.size();
        for(int i(2); i < n; i++)
        {
            cost[i] += std::min(cost[i - 1], cost[i - 2]);
        }

        return std::min(cost[n - 1], cost[n - 2]);
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> cost = {10,15,20};
        assert(sol.minCostClimbingStairs(cost) == 15);
    }
    {
        std::vector<int> cost = {1,100,1,1,1,100,1,1,100,1};
        assert(sol.minCostClimbingStairs(cost) == 6);
    }
    return 0;
}