#include <iostream>
#include <assert.h>

#include <algorithm>
#include <vector>

class Solution {
public:
    int twoCitySchedCost(std::vector<std::vector<int>>& costs) {
        std::ios::sync_with_stdio(0);
        std::sort(costs.begin(), costs.end(), [](auto &a, auto &b) {
            return a[0] - a[1] < b[0] - b[1];
        });
        
        int res = 0;
        int n = costs.size() / 2;
        for(int i = 0; i < n; i++) {
            res += costs[i][0] + costs[2 * n - i - 1][1];
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<std::vector<int>>  costs = {{10,20},{30,200},
                                                {400,50},{30,20}};
        int res = 110;
        assert(sol.twoCitySchedCost(costs) == res);
    }
    return 0;
}