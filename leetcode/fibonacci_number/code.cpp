#include <iostream>
#include <assert.h>

class Solution {
public:
    int fib(int n) {
        if(n == 0)
        {
            return 0;
        }
        if(n <= 2)
        {
            return 1;
        }
        int a(1), b(1);
        for(int i(3); i <= n; i++)
        {
            int temp = a + b;
            a = b;
            b = temp;
        }
        return b;
    }
};

int main()
{
    Solution sol;
    {
        assert(sol.fib(2) == 1);
        assert(sol.fib(3) == 2);
        assert(sol.fib(4) == 3);
    }
    return 0;
}