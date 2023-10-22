#include <iostream>
#include <assert.h>

class Solution {
public:
    int numberOfMatches(int n) {
        int res = 0;
        while(n)
        {
            res += n / 2;
            if(n != 1 && n % 2 == 1)
            {
                n++;
            }
            n /= 2;
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        int n = 7;
        int res = 6;
        assert(sol.numberOfMatches(n) == res);
    }
    {
        int n = 14;
        int res = 13;
        assert(sol.numberOfMatches(n) == res);
    }
    return 0;
}