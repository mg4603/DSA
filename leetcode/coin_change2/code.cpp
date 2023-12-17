#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    int change(int amount, std::vector<int>& coins) 
    {
        int n = coins.size();
        std::vector<std::vector<int>> table(n, 
                            std::vector<int>(amount + 1, 0));

        for(int i = 0; i < n; i++)
        {
            table[i][0] = 1;
        }

        for(int i = 0; i < n; i++)
        {
            for(int j = 1; j < amount + 1; j++)
            {
                
                if(j >= coins[i])
                {
                    table[i][j] += table[i][j-coins[i]];
                }
                
                if(i - 1 < 0)continue;
                table[i][j] += table[i - 1][j];
            }
        }
        return table[n - 1][amount];
    }
};

int main()
{
    Solution sol;
    {
        int amount = 5;
        std::vector<int> coins = {1,2,5};
        int res = 4;
        assert(sol.change(amount, coins) == res);
    }
    {
        int amount = 3;
        std::vector<int> coins = {2};
        int res = 0;
        assert(sol.change(amount, coins) == res);
    }
    {
        int amount = 10;
        std::vector<int> coins = {10};
        int res = 1;
        assert(sol.change(amount, coins) == res);
    }
    return 0;
}