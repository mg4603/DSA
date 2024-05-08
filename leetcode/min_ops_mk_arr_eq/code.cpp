#include <iostream>
#include <assert.h>

class Solution {
public:
    int minOperations(int n) {
        int a = n % 2 ? 2 : 1;
        n /= 2;
        n = n * (2 * a + (n - 1) * 2) / 2;
        return n;
    }
};

int main()
{
    Solution sol;
    {
        int n = 3;
        int res = 2;
        assert(sol.minOperations(n) == res);
    }
    return 0;
}