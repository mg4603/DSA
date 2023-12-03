#include <iostream>
#include <assert.h>

#include <vector>
#include <limits>

class Solution {
public:
    int getMoneyAmount(int n) 
    {
        std::vector<std::vector<int>> table(n + 1, 
                                        std::vector<int>(n + 1, 0));

        for(int len = 2; len <= n; len++)
        {
            for(int start = 1; start <= n - len + 1; start++)
            {
                int min_cost = std::numeric_limits<int>::max();
                for(int piv = start + (len - 1) / 2; piv < start + len - 1; piv++)
                {
                    int cost = piv + std::max(table[start][piv-1], 
                                            table[piv + 1][start + len -1]);
                    if(cost < min_cost)
                    {
                        min_cost = cost;
                    }
                }
                table[start][start + len - 1] = min_cost;
            }
        }
        return table[1][n];
    }
};

int main()
{
    Solution sol;
    {
        int n = 10;
        int res = 16;
        assert(sol.getMoneyAmount(n) == res);
    }
    {
        int n = 1;
        int res = 0;
        assert(sol.getMoneyAmount(n) == res);
    }
    {
        int n = 2;
        int res = 1;
        assert(sol.getMoneyAmount(n) == res);
    }
    return 0;
}