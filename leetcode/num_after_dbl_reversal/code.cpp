#include <iostream>
#include <assert.h>

class Solution {
public:
    bool isSameAfterReversals(int num) {
        return num < 10 || num % 10 != 0;
    }
};

int main()
{
    Solution sol;
    {
        int num = 526;
        int res = 1;
        assert(sol.isSameAfterReversals(num) == res);
    }
    {
        int num = 1800;
        int res = 0;
        assert(sol.isSameAfterReversals(num) == res);
    }
    {
        int num = 0;
        int res = 1;
        assert(sol.isSameAfterReversals(num) == res);
    }
    return 0;
}