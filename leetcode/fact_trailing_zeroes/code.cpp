#include <iostream>
#include <assert.h>

class Solution {
public:
    int trailingZeroes(int n) 
    {
         int res = 0;
         while(n)
         {
             res += n / 5;
             n /= 5;
         } 
         return res;
    }
};

int main()
{
    Solution sol;
    {
        int n = 3;
        int res = 0;
        assert(sol.trailingZeroes(n) == res);
    }
    {
        int n = 5;
        int res = 1;
        assert(sol.trailingZeroes(n) == res);
    }
    {
        int n = 0;
        int res = 0;
        assert(sol.trailingZeroes(n) == res);
    }
    return 0;
}