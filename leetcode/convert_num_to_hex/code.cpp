#include <iostream>
#include <assert.h>

class Solution {
    const std::string HEX = "0123456789abcdef";
public:
    std::string toHex(int num) {
        if(num == 0)
        {
            return "0";
        }
        std::string res;
        int count(0); // for negatives
        while(num && count++ < 8)
        {
            res = HEX[num & 0xf] + res;
            num >>= 4;
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        assert(sol.toHex(26) == "1a");
        assert(sol.toHex(-1) == "ffffffff");
    }
    return 0;
}