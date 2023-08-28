#include <iostream>
#include <assert.h>

#include <vector>
#include <limits>

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        int res(0);
        int leastCost(std::numeric_limits<int>::max());

        int currentProfits(0);
        for(int i(0); i < prices.size(); i++)
        {
            if(prices[i] < leastCost)
            {
                leastCost = prices[i];
            }
            currentProfits = prices[i] - leastCost;
            if(currentProfits > res)
            {
                res = currentProfits;
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> vec = {7,1,5,3,6,4};
        assert(sol.maxProfit(vec) == 5);
    }
    {
        std::vector<int> vec = {7,6,4,3,1};
        assert(sol.maxProfit(vec) == 0);
    }

    return 0;
}