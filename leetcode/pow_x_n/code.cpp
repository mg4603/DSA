#include <iostream>
#include <assert.h>

class Solution {
public:
    double myPow(double x, int n) 
    {

        long exp = static_cast<long>(n);

        if(exp < 0)
        {
            x = 1/x;
            exp = -exp;
        }
        
        double res = 1.0;
        while(exp != 0)
        {
            if((exp & 1) != 0)
            {
                res *= x;
            }
            x *= x;
            exp >>= 1;
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        double x = 2.00000;
        int n = 10;
        double res = 1024.00000;
        assert(sol.myPow(x, n) == res);
    }
    {
        double x = 2.10000;
        int n = 3;
        double res = 9.26100;
        assert(std::abs(sol.myPow(x, n) - res) < 10e-5);
    }
    {
        double x = 2.00000;
        int n = -2;
        double res = 0.25000;
        assert(sol.myPow(x, n) == res);
    }
    return 0;
}