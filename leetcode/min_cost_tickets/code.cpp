#include <iostream>
#include <assert.h>

#include <vector>
#include <algorithm>

class Solution {
    int solve(std::vector<int> &days, std::vector<int> &costs, 
                int i, std::vector<int> &memo) {
        if(i >= days.size())return 0;
        if(memo[i] != -1)return memo[i];

        memo[i] = std::min({costs[0] + solve(days, costs, 
                                             i + 1, memo), 
            costs[1] + solve(days, costs, 
                            std::upper_bound(days.begin(), 
                            days.end(), days[i] + 6) - 
                            days.begin(), memo),
            costs[2] + solve(days, costs, 
                            std::upper_bound(days.begin(), 
                            days.end(), days[i] + 29) - 
                            days.begin(), memo)});
        return memo[i];
    }
public:
    int mincostTickets(std::vector<int>& days, 
                        std::vector<int>& costs) {
        std::ios::sync_with_stdio(0);
        std::vector<int> memo(days.size(), -1);
        return solve(days, costs, 0, memo);
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> days = {1,4,6,7,8,20};
        std::vector<int> costs = {2,7,15};
        int res = 11;
        assert(sol.mincostTickets(days, costs) == res);
    }
    return 0;
}