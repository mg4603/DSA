#include <iostream>
#include <assert.h>

class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n <= 0)
        {
            return false;
        }
        while(n % 3 == 0)
        {
            n /= 3;
        }
        return n == 1;
    }
};

int main()
{
    Solution sol;
    {
        assert(sol.isPowerOfThree(27) == true);
        assert(sol.isPowerOfThree(0) == false);
        assert(sol.isPowerOfThree(-1) == false);
    }
    return 0;
}