#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    int climbStairs(int n) {
        if(n == 0 || n == 1)
        {
            return 1;
        }

        std::vector<int> dp(n + 1);
        dp[0] = dp[1] = 1;
        for(int i(2); i <= n; i++)
        {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};

int main()
{
    Solution sol;
    {
        assert(sol.climbStairs(2) == 2);
        assert(sol.climbStairs(3) == 3);
    }
    return 0;
}