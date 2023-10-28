#include <iostream>
#include <assert.h>

class Solution {
public:
    int smallestEvenMultiple(int n) {
        return n % 2 == 0 ? n : n * 2;
    }
};

int main()
{
    Solution sol;
    {
        int n = 5;
        int res = 10;
        assert(sol.smallestEvenMultiple(n) == res);
    }
    {
        int n = 6;
        int res = 6;
        assert(sol.smallestEvenMultiple(n) == res);
    }
    return 0;
}