#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    int countVowelStrings(int n) {
        std::ios::sync_with_stdio(0);
        std::vector<int> dp(6, 1);
        dp[0] = 0;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j < 6; j++) {
                dp[j] += dp[j - 1];
            }
        }
        return dp[5];
    }
};

int main()
{
    Solution sol;
    {
        int n = 1;
        int res = 5;
        assert(sol.countVowelStrings(n) == res);
    }
    return 0;
}