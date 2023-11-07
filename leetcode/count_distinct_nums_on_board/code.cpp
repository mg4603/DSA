#include <iostream>
#include <assert.h>

class Solution {
public:
    int distinctIntegers(int n) 
    {
        if(n == 1)
        {
            return n;
        }
        return n - 1;
    }
};

int main()
{
    Solution sol;
    {
        int n = 5;
        int res = 4;
        assert(sol.distinctIntegers(n) == res);
    }
    {
        int n = 3;
        int res = 2;
        assert(sol.distinctIntegers(n) == res);
    }
    return 0;
}