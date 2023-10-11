#include <iostream>
#include <assert.h>

class Solution {
public:
    long tribonacci(int n) {
        std::ios_base::sync_with_stdio(0);
        long a = 0;
        long b = 1;
        long c = 1;

        while(n--)
        {
            long temp = a + b + c;
            a = b;
            b = c;
            c = temp;
        }
        return a;
    }
};

int main()
{
    Solution sol;
    {
        int n = 4;
        int res = 4;
        assert(sol.tribonacci(n) == res);
    }
    {
        int n = 25;
        int res = 1389537;
        assert(sol.tribonacci(n) == res);
    }
    return 0;
}