#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
    int helper(int i, int n, std::vector<int> &table)
    {
        if(n == 0)
        {
            return 0;
        }
        if(i * i > n)
        {
            return 10e8;
        }
        if(table[n] != -1)
        {
            return table[n];
        }

        if(i * i <= n)
        {
            table[n] = std::min(1 + helper(i, n - i * i, table), 
                                helper(i + 1, n, table));
        }
        
        return table[n];
    }
public:
    int numSquares(int n) 
    {
        std::vector<int> table(n + 1, -1);
        
        return helper(1, n, table);
    }
};

int main()
{
    Solution sol;
    {
        int n = 12;
        int res = 3;
        assert(sol.numSquares(n) == res);
    }
    {
        int n = 13;
        int res = 2;
        assert(sol.numSquares(n) == res);
    }
    return 0;
}