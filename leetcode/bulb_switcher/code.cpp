#include <iostream>
#include <assert.h>

#include <cmath>

// ith bulb will be on if i has odd number of factors
// i will only have odd number of factors if it is a perfect
// square since all other factors occur in pairs (a * b = i)
// where a and b are factors of i

class Solution {
public:
    int bulbSwitch(int n) 
    {
        return std::sqrt(n);
    }
};

int main()
{
    Solution sol;
    {
        int n = 3;
        int res = 1;
        assert(sol.bulbSwitch(n) == res);
    }
    {
        int n = 0;
        int res = 0;
        assert(sol.bulbSwitch(n) == res);
    }
    {
        int n = 1;
        int res = 1;
        assert(sol.bulbSwitch(n) == res);
    }
    return 0;
}