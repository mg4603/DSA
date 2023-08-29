#include <iostream>
#include <assert.h>

#include <cmath>

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n == 0)
        {
            return false;
        }
        double temp = std::log2(n);
        return (std::floor(temp) == temp);
    }
};

int main()
{
    Solution sol;
    {
        assert(sol.isPowerOfTwo(1) == true);
    }
    {
        assert(sol.isPowerOfTwo(16) == true);
    }
    {
        assert(sol.isPowerOfTwo(3) == false);
    }
    return 0;
}