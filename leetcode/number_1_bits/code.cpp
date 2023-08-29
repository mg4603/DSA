#include <iostream>
#include <assert.h>

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res(0);
        while(n)
        {
            if(n % 2 == 1)
            {
                res++;
            }
            n /= 2;
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        assert(sol.hammingWeight(19) == 3);
    }
    {
        assert(sol.hammingWeight(128) == 1);
    }
    {
        assert(sol.hammingWeight(4294967293) == 31);
    }
    return 0;
}