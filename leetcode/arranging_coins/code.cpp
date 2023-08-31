#include <iostream>
#include <assert.h>

class Solution {
public:
    int arrangeCoins(int n) {
        int count(0);
        int i(1);
        while(i <= n)
        {
            n -= i;
            i++;
            count++;
        }
        return count;
    }
};

int main()
{
    Solution sol;
    {
        assert(sol.arrangeCoins(5) == 2);
        assert(sol.arrangeCoins(8) == 3);
    }
    return 0;
}