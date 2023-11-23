#include <iostream>
#include <assert.h>

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) 
    {
        int res = right;
        while(res > left)
        {
            res = res & (res - 1);
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        int left = 5;
        int right = 7;
        int res = 4;
        assert(sol.rangeBitwiseAnd(left, right) == res);
    }
    {
        int left = 0;
        int right = 0;
        int res = 0;
        assert(sol.rangeBitwiseAnd(left, right) == res);
    }
    {
        int left = 1;
        int right = 2147483647;
        int res = 0;
        assert(sol.rangeBitwiseAnd(left, right) == res);
    }
    return 0;
}