#include <iostream>
#include <assert.h>

class Solution {
public:
    bool isThree(int n) {
        int divisors = 2;
        for(int i = 2; i * i <= n; i++)
        {
            if(n % i == 0)
            {
                if(n / i != i || ++divisors > 3)
                {
                    return false;
                }
            }
        }
        return divisors == 3;
    }
};

int main()
{
    Solution sol;
    {
        int n = 2;
        int res = 0;
        assert(sol.isThree(n) == res);
    }
    {
        int n = 4;
        int res = 1;
        assert(sol.isThree(n) == res);
    }
    return 0;
}