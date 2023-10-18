#include <iostream>
#include <assert.h>

class Solution {
public:
    int xorOperation(int n, int start) {
        int res = 0;
        for(int i = 0; i < n; i++)
        {
            res ^= (start + (2 * i));
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        int n = 5;
        int start = 0;
        int res = 8;
        assert(sol.xorOperation(n, start) == res);
    }
    {
        int n = 4;
        int start = 3;
        int res = 8;
        assert(sol.xorOperation(n, start) == res);
    }
    return 0;
}