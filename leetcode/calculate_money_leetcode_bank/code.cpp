#include <iostream>
#include <assert.h>

class Solution {
public:
    int totalMoney(int n) {
        int res = 0;
        int cnt = 0;
        int seven = (7 * (7 + 1) / 2);
        while(n)
        {
            if(n / 7 > 0)
            {
                res += seven;
                res += (cnt * 7);
                cnt++;
                n -= 7;
            }
            else
            {
                res += (n * (n + 1) / 2);
                res += (cnt * n);
                n = 0;
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        int n = 4;
        int res = 10;
        assert(sol.totalMoney(n) == res);
    }
    {
        int n = 10;
        int res = 37;
        assert(sol.totalMoney(n) == res);
    }
    {
        int n = 20;
        int res = 96;
        assert(sol.totalMoney(n) == res);
    }
    return 0;
}