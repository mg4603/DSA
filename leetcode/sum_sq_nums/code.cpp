#include <iostream>
#include <assert.h>

#include <cmath>

class Solution {
public:
    bool judgeSquareSum(int c) 
    {
        if(c <= 0)
        {
            return true;
        }

        long long r = std::sqrt(c);
        long long l = 0;

        while(l <= r)
        {
            long long temp = l * l + r * r ;
            if(temp == c)
            {
                return true;
            }
            else if(temp < c)
            {
                l++;
            }
            else
            {
                r--;
            }
        }
        return false;
    }
};

int main()
{
    Solution sol;
    {
        int c = 5;
        bool res = true;
        assert(sol.judgeSquareSum(c) == res);
    }
    {
        int c = 3;
        bool res = false;
        assert(sol.judgeSquareSum(c) == res);
    }
    return 0;
}