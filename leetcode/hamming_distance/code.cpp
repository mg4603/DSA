#include <iostream>
#include <assert.h>

#include <bitset>

class Solution {
public:
    int hammingDistance(int x, int y) {
        std::bitset<32> x_bitset(x);
        std::bitset<32> y_bitset(y);

        int res(0);

        for(int i(0); i < 32; i++)
        {
            if(x_bitset[i] ^ y_bitset[i])
            {
                res++;
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        assert(sol.hammingDistance(1, 4) == 2);
        assert(sol.hammingDistance(1, 3) == 1);
    }
    return 0;
}