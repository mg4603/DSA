#include <iostream>
#include <assert.h>

#include <vector>
#include <numeric>

class Solution {
    bool checkZero(int n)
    {
        while(n)
        {
            if(n % 10 == 0)
            {
                return false;
            }
            n /= 10;
        }
        return true;
    }
public:
    std::vector<int> getNoZeroIntegers(int n) {
        std::ios_base::sync_with_stdio(0);
        for(int i = 1; i <= n / 2; i++)
        {
            if(checkZero(i) && checkZero(n - i))
            {
                return {i, n - i};
            }
        }
        return {0, 0};
    }
};

int main()
{
    Solution sol;
    {
        int n = 2;
        std::vector<int> res = sol.getNoZeroIntegers(n);
        assert(std::accumulate(res.begin(), res.end(), 0)== n);
    }
    {
        int n = 11;
        std::vector<int> res = sol.getNoZeroIntegers(n);
        assert(std::accumulate(res.begin(), res.end(), 0)== n);
    }
    return 0;
}