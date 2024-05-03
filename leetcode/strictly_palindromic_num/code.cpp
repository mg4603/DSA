#include <iostream>
#include <assert.h>

class Solution {
public:
    bool isStrictlyPalindromic(int n) {
        return false;
    }
};

int main()
{
    Solution sol;
    {
        int n = 9;
        bool res = false;
        assert(sol.isStrictlyPalindromic(n) == res);
    }
    return 0;
}