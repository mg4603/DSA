#include <iostream>
#include <assert.h>

#include <cmath>

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        std::string bit_string;
        while(n)
        {
            bit_string = std::to_string(n % 2) + bit_string;
            n /= 2;
        }
        if(bit_string.size() < 32)
        {
            bit_string = std::string(32 - bit_string.size(), '0') + bit_string;
        }
        uint32_t res(0);
        for(int i(0); i < bit_string.size(); i++)
        {
            res += std::pow(2, i) * (bit_string[i] - '0');
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        assert(sol.reverseBits(43261596) == 964176192);
    }
    {
        assert(sol.reverseBits(4294967293) == 3221225471);
    }
    return 0;
}