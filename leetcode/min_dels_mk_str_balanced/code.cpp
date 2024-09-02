#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    int minimumDeletions(std::string s) {
        std::ios::sync_with_stdio(0);
        int n = s.length();
        std::vector<int> dp(n + 1);
        int bcount = 0;

        for(int i = 0; i < n; i++) {
            if(s[i] == 'a') {
                dp[i + 1] = std::min(bcount, dp[i] + 1);
            }else {
                dp[i + 1] = dp[i];
                bcount++;
            }
        }

        return dp[n];
    }
};

int main()
{
    Solution sol;
    {
        std::string s = "aababbab";
        int res = 2;
        assert(sol.minimumDeletions(s) == res);
    }
    return 0;
}