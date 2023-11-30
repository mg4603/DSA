#include <iostream>
#include <assert.h>

#include <vector>
#include <limits>

class Solution {
public:
    int coinChange(std::vector<int>& coins, int amount) 
    {
        if(amount < 0)
        {
            return -1;
        }

        int n = coins.size();
        std::vector<int> table(amount + 1, 
                            std::numeric_limits<int>::max());
        table[0] = 0;
        
        for(int i = 1; i <= amount; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(coins[j] <= i && 
                   table[i - coins[j]] != 
                    std::numeric_limits<int>::max())
                {
                    table[i] = std::min(table[i], 
                                        1 + table[i - coins[j]]);
                }
            }
        }

        if(table[amount] == std::numeric_limits<int>::max())
        {
            return -1;
        }
        return table[amount];
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> coins = {1,2,5};
        int amount = 11;
        int res = 3;
        assert(sol.coinChange(coins, amount) == res);
    }
    {
        std::vector<int> coins = {2};
        int amount = 3;
        int res = -1;
        assert(sol.coinChange(coins, amount) == res);
    }
    {
        std::vector<int> coins = {1};
        int amount = 0;
        int res = 0;
        assert(sol.coinChange(coins, amount) == res);
    }
    return 0;
}