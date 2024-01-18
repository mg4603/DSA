#include <iostream>
#include <assert.h>

#include <limits>
#include <vector>

class Solution {
    int helper(int i, bool own, std::vector<int> &prices, 
                int fee, std::vector<std::vector<int>> &memo)
    {
        if(i >= prices.size())return 0;
        if(memo[i][own] != 
                std::numeric_limits<int>::min())return memo[i][own];

        int skip = std::numeric_limits<int>::min();
        int buy_sell = std::numeric_limits<int>::min();
        skip = helper(i + 1, own, prices, fee, memo);
        
        if(own)
        {
            buy_sell = helper(i + 1, false, prices, fee, memo) + 
                        prices[i] - fee;
        }
        else
        {
            buy_sell = helper(i + 1, true, prices, fee, memo) - 
                        prices[i];
        }
        memo[i][own] = std::max(skip, buy_sell);
        return memo[i][own];
    }
public:
    int maxProfit(std::vector<int>& prices, int fee) {
        std::vector<std::vector<int>> memo(prices.size(), 
                        std::vector<int>(2, 
                        std::numeric_limits<int>::min()));
        return helper(0, false, prices, fee, memo);
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> prices = {1,3,2,8,4,9};
        int fee = 2;
        int res = 8;
        assert(sol.maxProfit(prices, fee) == res);
    }
    return 0;
}