#include <iostream>
#include <assert.h>

class Solution {
public:
    std::string baseNeg2(int n) {
        std::string res;
        while(n) {
            res = std::to_string(n & 1) + res;
            n = -(n >> 1);
        }
        return res == "" ? "0" : res;
    }
};

int main()
{
    Solution sol;
    {
        int n = 2;
        std::string res = "110";
        assert(sol.baseNeg2(n) == res);
    }
    return 0;
}