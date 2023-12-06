#include <iostream>
#include <assert.h>

class Solution {
    int solve(long i, long n)
    {
        if(i < 0)
        {
            return 1e9;
        }

        if(i == 1)
        {
            return 0;
        }

        
        if(i % 2 == 1)
        {
          return 1 + std::min(solve(i - 1, n), solve(i + 1, n));
        }

        return 1 + solve(i/2, n);
    }
public:
    int integerReplacement(int n) 
    {
        return solve(n, n);
    }
};

int main()
{
    Solution sol;
    {
        int n = 8;
        int res = 3;
        assert(sol.integerReplacement(n) == res);
    }
    {
        int n = 7;
        int res = 4;
        assert(sol.integerReplacement(n) == res);
    }
    {
        int n = 4;
        int res = 2;
        assert(sol.integerReplacement(n) == res);
    }
    return 0;
}