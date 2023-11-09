#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    int numDecodings(std::string s) {
        if(s.length() == 0)
        {
            return 0;
        }
        int n = s.length();
        std::vector<int> dp(n + 1);
        dp[0] = 1;
        dp[1] = (s[0] == '0'? 0: 1);

        for(int i = 2; i <= n; i++)
        {
            int one = s[i - 2] - '0';
            int two = s[i - 1] - '0';

            if(two >= 1 && two <= 9)
            {
                dp[i] += dp[i - 1];
            }
            int temp = one * 10 + two;
            if(temp >= 10 && temp <= 26)
            {
                dp[i] += dp[i - 2];
            }
        }
        return dp[n];
    }
};

int main()
{
    Solution sol;
    {
        std::string s = "12";
        int res = 2;
        assert(sol.numDecodings(s) == res);
    }
    {
        std::string s = "226";
        int res = 3;
        assert(sol.numDecodings(s) == res);
    }
    {
        std::string s = "06";
        int res = 0;
        assert(sol.numDecodings(s) == res);
    }
    return 0;
}