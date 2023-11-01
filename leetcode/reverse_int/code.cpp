#include <iostream>
#include <assert.h>

#include <limits>

class Solution {
public:
    int reverse(int x) {
        int neg = 0;
        if(x == std::numeric_limits<int>::min() || 
            x == std::numeric_limits<int>::max())
        {
            return 0;
        }
        if(x < 0)
        {
            neg = 1;
            x = -x;
        }

        int res = 0;
        while(x)
        {
            if(res * 10L >= std::numeric_limits<int>::max())
            {
                return 0;
            }
            res *= 10;
            res += x % 10;
            x /= 10;
        } 

        if(neg)
        {
            return -res;
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        int x = 123;
        int res = 321;
        assert(sol.reverse(x) == res);
    }
    {
        int x = -123;
        int res = -321;
        assert(sol.reverse(x) == res);
    }
    {
        int x = 120;
        int res = 21;
        assert(sol.reverse(x) == res);
    }
    return 0;
}