#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    std::vector<int> finalPrices(std::vector<int>& prices) {
        std::ios_base::sync_with_stdio(0);
        int n = prices.size();
        for(int i = 0; i < n; i++)
        {
            for(int j = i + 1; j < n; j++)
            {
                if(prices[j] <= prices[i])
                {
                    prices[i] -= prices[j];
                    break;
                }
            }
        }

        return prices;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> prices = {8,4,6,2,3};
        std::vector<int> res = {4,2,4,2,3};
        
        assert(sol.finalPrices(prices) == res);
    }
    {
        std::vector<int> prices = {1,2,3,4,5};
        std::vector<int> res = {1,2,3,4,5};
        
        assert(sol.finalPrices(prices) == res);
    }
    {
        std::vector<int> prices = {10,1,1,6};
        std::vector<int> res = {9,0,1,6};
        
        assert(sol.finalPrices(prices) == res);
    }

    return 0;
}