#include <iostream>
#include <assert.h>

class Solution {
public:
    int sumOfMultiples(int n) {
        int res = 0;
        for(int i = 3; i <= n; i++)
        {
            if(i % 3 == 0 || i % 5 == 0 || i % 7 == 0)
            {
                res += i;
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        int n = 7;
        int res = 21;
        assert(sol.sumOfMultiples(n) == res);
    }
    {
        int n = 10;
        int res = 40;
        assert(sol.sumOfMultiples(n) == res);
    }
    {
        int n = 9;
        int res = 30;
        assert(sol.sumOfMultiples(n) == res);
    }
    return 0;
}