#include <iostream>
#include <assert.h>

class Solution {
public:
    int mySqrt(long long x) {
        if(x == 0)
        {
            return 0;
        }
        long long num(1);
        while((num + 1) * (num + 1) <= x)
        {
            num++;
        }
        return num;
        // return sqrt(x);
    }
};

int main()
{
    Solution sol;
    {
        assert(sol.mySqrt(4) == 2);
        assert(sol.mySqrt(8) == 2);
    }
    return 0;
}