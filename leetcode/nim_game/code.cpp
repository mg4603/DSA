#include <iostream>
#include <assert.h>

class Solution {
public:
    bool canWinNim(int n) {
        return n % 4;
    }
};

int main()
{
    Solution sol;
    {
        assert(sol.canWinNim(4) == false);
        assert(sol.canWinNim(1) == true);
        assert(sol.canWinNim(2) == true);
    }
    return 0;
}