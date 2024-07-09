#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    std::vector<bool> canEat(std::vector<int>& candiesCount, 
                            std::vector<std::vector<int>>& queries) {
        std::ios::sync_with_stdio(0);
        int n = candiesCount.size();
        std::vector<long long> presum(n + 1, 0LL);
        for(int i = 1; i <= n; i++)
        {
            presum[i] = presum[i - 1] + candiesCount[i - 1];
        }

        int m = queries.size();
        std::vector<bool> res(m);
        for(int i = 0; i < m; i++)
        {
            int favourite_type = queries[i][0];
            int favourite_day = queries[i][1];
            int daily_cap = queries[i][2];

            long long lower = presum[favourite_type] / daily_cap;
            if(favourite_day >= lower && 
                favourite_day <= presum[favourite_type + 1] - 1)res[i] = 1;
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> candiesCount = {7,4,5,3,8};
        std::vector<std::vector<int>> queries = {{0,2,2},{4,2,4},{2,13,1000000000}};
        std::vector<bool> res = {1, 0, 1};
        assert(sol.canEat(candiesCount, queries) == res);
    }
    return 0;
}