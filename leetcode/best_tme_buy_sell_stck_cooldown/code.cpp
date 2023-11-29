#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
    int helper(std::vector<int> &prices, 
               std::vector<std::vector<int>> &table, 
               int i, int buy)
    {
        int n = prices.size();
        if(i >= n - 1)
        {
            if(buy)
            {
                return 0;
            }
            else
            {
                if(i == n - 1)
                {
                    return prices[i];
                }
                else
                {
                    return 0;
                }
            }
        }

        if(table[i][buy] != -1)
        {
            return table[i][buy];
        }

        int take = 0;
        int dont_take = 0;

        if(buy)
        {
            take = -prices[i] + helper(prices, table, 
                                       i + 1, 1 - buy);
            dont_take = helper(prices, table, i + 1, buy);
        }
        else
        {
            take = prices[i] + helper(prices, table, 
                                      i + 2, 1 + buy);
            dont_take = helper(prices, table, i + 1, buy);
        }
        table[i][buy] = std::max(take, dont_take);
        return table[i][buy];
    }
public:
    int maxProfit(std::vector<int>& prices) 
    {
        int n = prices.size();
        std::vector<std::vector<int>> table(n + 1, 
                                        std::vector<int>(2, -1));
        return helper(prices, table, 0, 1);
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> prices = {1,2,3,0,2};
        int res = 3;
        assert(sol.maxProfit(prices) == res);
    }
    {
        std::vector<int> prices = {1};
        int res = 0;
        assert(sol.maxProfit(prices) == res);
    }
    return 0;
}