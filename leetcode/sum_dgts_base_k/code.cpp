#include <iostream>
#include <assert.h>

class Solution {
public:
    int sumBase(int n, int k) {
        int res = 0;
        while(n)
        {
            res += n % k;
            n /= k;
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        int n = 34;
        int k = 6;
        int res = 9;
        assert(sol.sumBase(n, k) == res);
    }
    {
        int n = 10;
        int k = 10;
        int res = 1;
        assert(sol.sumBase(n, k) == res);
    }
    return 0;
}