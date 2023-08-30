#include <iostream>
#include <assert.h>

class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n <= 0)
        {
            return false;
        }
        while(n % 4 == 0)
        {
            n /= 4;
        }
        return n == 1;
    }
};

int main()
{
    Solution sol;
    {
        assert(sol.isPowerOfFour(16) == true);
        assert(sol.isPowerOfFour(5) == false);
        assert(sol.isPowerOfFour(1) == true);
    }
    return 0;
}