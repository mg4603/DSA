#include <iostream>
#include <assert.h>

#include <cmath>

class Solution {
public:
    int integerBreak(int n) 
    {
        if(n <= 2)
        {
            return 1;
        }

        if(n == 3)
        {
            return 2;
        }

        int threes = 0;
        while(n > 4)
        {
            n -= 3;
            threes++;
        }  

        return std::pow(3, threes) * n;
    }
};

int main()
{
    Solution sol;
    {
        int n = 2;
        int res = 1;
        assert(sol.integerBreak(n) == res);
    }
    {
        int n = 10;
        int res = 36;
        assert(sol.integerBreak(n) == res);
    }
    return 0;
}