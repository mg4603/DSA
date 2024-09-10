#include <iostream>
#include <assert.h>

class Solution {
public:
    double nthPersonGetsNthSeat(int n) {
        return n == 1 ? 1 : 0.5;
    }
};

int main()
{
    Solution sol;
    {
        int n = 1;
        double res = 1.00000;

        assert(sol.nthPersonGetsNthSeat(n) == res);
    }
    return 0;
}