#include <iostream>
#include <assert.h>

#include <cmath>

class Solution {
public:
    int countTriples(int n) {
        int res = 0;
        for(int i = 1; i <= n; i++)
        {
            for(int j = i; j <= n; j++)
            {
                double c = std::sqrt(i * i + j * j);
                if(c <= n && c == static_cast<int> (c))
                {
                    res += 2;
                }
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        int n = 5;
        int res = 2;
        assert(sol.countTriples(n) == res);
    }
    {
        int n = 10;
        int res = 4;
        assert(sol.countTriples(n) == res);
    }
    return 0;
}