#include <iostream>
#include <assert.h>

class Solution {
public:
    int pivotInteger(int n) 
    {
        int left = 0;
        int right = n * (n + 1)/2;

        for(int i = 1; i < (n + 1); i++)
        {
            left += i;
            if(left == right)
            {
                return i;
            }
            right -= i;
        }
        return -1;
    }
};

int main()
{
    Solution sol;
    {
        int n = 8;
        int res = 6;
        assert(sol.pivotInteger(n) == res);
    }
    {
        int n = 1;
        int res = 1;
        assert(sol.pivotInteger(n) == res);
    }
    {
        int n = 4;
        int res = -1;
        assert(sol.pivotInteger(n) == res);
    }
    return 0;
}