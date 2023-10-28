#include <iostream>
#include <assert.h>

#include <cmath>

class Solution {
public:
    int alternateDigitSum(int n) {
        int res = 0;
        int parity = 1;

        int exp = std::log10(n);
        while(n)
        {
            int divisor = std::pow(10, exp--);
            res += parity * (n / divisor);
            parity *= -1;
            n %= divisor;
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        int n = 521;
        int res = 4;
        assert(sol.alternateDigitSum(n) == res);
    }
    {
        int n = 111;
        int res = 1;
        assert(sol.alternateDigitSum(n) == res);
    }
    {
        int n = 886996;
        int res = 0;
        assert(sol.alternateDigitSum(n) == res);
    }
    return 0;
}