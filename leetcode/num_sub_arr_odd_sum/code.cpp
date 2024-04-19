#include <iostream>
#include <assert.h>

#include <vector>
#include <array>

class Solution {
    const int mod = 1e9+7;
public:
    int numOfSubarrays(std::vector<int>& arr) {
        std::ios::sync_with_stdio(0);
        int n = arr.size();
        std::vector<std::array<int, 2>> dp(n, {0, 0});

        if(arr[n - 1] % 2)
        {
            dp[n - 1][1] = 1;
        }
        else
        {
            dp[n - 1][0] = 1;
        }

        for(int i = n - 2; i >= 0; i--)
        {
            if(arr[i] % 2)
            {
                dp[i][1] = (1 + dp[i + 1][0]) % mod;
                dp[i][0] = dp[i + 1][1];
            }
            else
            {
                dp[i][0] = (dp[i + 1][0] + 1) % mod;
                dp[i][1] = dp[i + 1][1];
            }
        }

        int res = 0;
        for(int i = 0; i < n; i++)
        {
            res += dp[i][1];
            res %= mod;
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> arr = {1,3,5};
        int res = 4;
        assert(sol.numOfSubarrays(arr) == res);
    }
    return 0;
}