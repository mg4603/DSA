#include <iostream>
#include <assert.h>

#include <cmath>
#include <limits>

class Solution {
public:
    int divide(int dividend, int divisor) 
    {
        if(dividend == divisor)
        {
            return 1;
        }
        bool neg = ((dividend < 0) != (divisor < 0));
        unsigned int a = std::abs(dividend);
        unsigned int b = std::abs(divisor);
        unsigned int ans = 0;

        while(a >= b)
        {
            short q = 0;
            while(a > (b << (q + 1)))
            {
                q++;
            }
            ans += (1 << q);
            a -= (b << q);
        }
        if(ans == (1 << 31) && !neg)
        {
            return std::numeric_limits<int>::max();
        }
        return neg? -ans: ans;
    }
};

int main()
{
    Solution sol;
    {
        int dividend = 10;
        int divisor = 3;
        int res = 3;
        assert(sol.divide(dividend, divisor) == res);
    }
    {
        int dividend = 7;
        int divisor = -3;
        int res = -2;
        assert(sol.divide(dividend, divisor) == res);
    }
    return 0;
}