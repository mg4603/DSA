#include <iostream>
#include <assert.h>

#include <vector>
#include <numeric>

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) 
    {
        if(n == 0)
        {
            return 1;
        }
        std::vector<int> res(n + 1, 0);
        res[0] = 1;
        res[1] = 9;

        for(int i = 2; i < n + 1; i++)
        {
            int ans = 9;
            int count = 9;
            for(int j = 1; j < i; j++)
            {
                ans *= count--;
            }
            res[i] = ans;
        }        

        return std::accumulate(res.begin(), res.end(), 0);
    }
};

int main()
{
    Solution sol;
    {
        int n = 2;
        int res = 91;
        assert(sol.countNumbersWithUniqueDigits(n) == res);
    }
    {
        int n = 0;
        int res = 1;
        assert(sol.countNumbersWithUniqueDigits(n) == res);
    }
    return 0;
}