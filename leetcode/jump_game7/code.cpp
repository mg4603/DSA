#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    bool canReach(std::string s, int minJump, int maxJump) {
        int n = s.length();
        std::vector<bool> dp(n, false);
        dp[0] = 1;
        int pre = 0;
        for(int i = 1; i < n; i++)
        {
            if(i >= minJump)
            {
                pre += dp[i - minJump];
            }
            if(i > maxJump)
            {
                pre -= dp[i - maxJump - 1];
            }
            dp[i] = pre > 0 && s[i] == '0';
        }
        return dp[n - 1];
    }
};

int main()
{
    Solution sol;
    {
        std::string s = "011010";
        int minJump = 2;
        int maxJump = 3;
        bool res = true;
        assert(sol.canReach(s, minJump, maxJump) == res);
    }
    return 0;
}