#include <iostream>
#include <assert.h>

class Solution {
public:
    bool divisorGame(int n) {
        return n % 2 == 0;
    }
};

int main()
{
    Solution sol;
    {
        int n = 2;
        bool res = true;
        assert(sol.divisorGame(n) == res);
    }
    {
        int n = 3;
        bool res = false;
        assert(sol.divisorGame(n) == res);
    }
    return 0;
}