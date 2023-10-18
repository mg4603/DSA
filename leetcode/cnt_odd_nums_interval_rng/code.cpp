#include <iostream>
#include <assert.h>

class Solution {
public:
    int countOdds(int low, int high) {
        int n = (high - low) / 2;
        if(low % 2 == 1 || high % 2 == 1)
        {
            n++;
        }
        return n;
    }
};

int main()
{
    Solution sol;
    {
        int low = 3;
        int high = 7;
        int res = 3;
        assert(sol.countOdds(low, high) == res);
    }
    {
        int low = 8;
        int high = 10;
        int res = 1;
        assert(sol.countOdds(low, high) == res);
    }
    return 0;
}