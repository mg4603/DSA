#include <iostream>
#include <assert.h>

class Solution {
public:
    int minFlips(int a, int b, int c) {
        int res = __builtin_popcount((a | b) ^ c);
        res += __builtin_popcount(a & b & ((a | b) ^ c));
        return res;
    }
};

int main()
{
    Solution sol;
    {
        int a = 2, b = 6, c = 5;
        int res = 3;
        assert(sol.minFlips(a, b, c) == res);
    }
    return 0;
}