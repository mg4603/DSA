#include <iostream>
#include <assert.h>

class Solution {
public:
    int numberOfCuts(int n) {
        if(n == 1)
        {
            return 0;
        }
        return n % 2 == 0 ? n / 2: n;
    }
};

int main()
{
    Solution sol;
    {
        int n = 4;
        int res = 2;
        assert(sol.numberOfCuts(n) == res);
    }
    {
        int n = 3;
        int res = 3;
        assert(sol.numberOfCuts(n) == res);
    }
    return 0;
}