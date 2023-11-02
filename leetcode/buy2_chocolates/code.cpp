#include <iostream>
#include <assert.h>

#include <vector>
#include <algorithm>

class Solution {
public:
    int buyChoco(std::vector<int>& prices, int money) 
    {
        std::sort(prices.begin(), prices.end());

        int temp = prices[0] + prices[1];
        if(money - temp < 0)
        {
            return money;
        }
        return money - temp;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> prices = {1,2,2};
        int money = 3;
        int res = 0;
        assert(sol.buyChoco(prices, money) == res);
    }
    {
        std::vector<int> prices = {3,2,3};
        int money = 3;
        int res = 3;
        assert(sol.buyChoco(prices, money) == res);
    }
    return 0;
}