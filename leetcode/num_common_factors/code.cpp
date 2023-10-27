#include <iostream>
#include <assert.h>

#include <cmath>

class Solution {
    int gcd(int a, int b)
    {
        if(b == 0)
        {
            return a;
        }
        return gcd(b, a % b);
    }
public:
    int commonFactors(int a, int b) {
        int temp = gcd(a, b);
        int res = 0;
        
        for(int i = 1; i <= std::sqrt(temp); i++)
        {
            if(temp % i == 0 && temp / i != i)
            {
                res += 2;
            }
            else if(temp % i == 0)
            {
                res += 1;
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        int a = 12;
        int b = 6;
        int res = 4;
        assert(sol.commonFactors(a, b) == res);
    }
    {
        int a = 25;
        int b = 30;
        int res = 2;
        assert(sol.commonFactors(a, b) == res);
    }
    return 0;
}