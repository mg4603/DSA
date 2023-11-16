#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    int maxProfit(std::vector<int>& prices) 
    {
        int res = 0;
        int buy_day = 0;
        int sell_day = 0;

        for(int i = 1; i < prices.size(); i++)
        {
            if(prices[i] >= prices[i - 1])
            {
                sell_day++;
            }
            else
            {
                res += prices[sell_day] - prices[buy_day];
                sell_day = i;
                buy_day = i;
            }
        }

        res += prices[sell_day] - prices[buy_day];
        return res;   
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> prices = {7,1,5,3,6,4};
        int res = 7;
        assert(sol.maxProfit(prices) == res);
    }
    {
        std::vector<int> prices = {1,2,3,4,5};
        int res = 4;
        assert(sol.maxProfit(prices) == res);
    }
    {
        std::vector<int> prices = {7,6,4,3,1};
        int res = 0;
        assert(sol.maxProfit(prices) == res);
    }
    return 0;
}