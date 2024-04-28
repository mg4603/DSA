#include <iostream>
#include <assert.h>

#include <vector>
#include <deque>

class Solution {
public:
    int minimumCoins(std::vector<int>& prices) {
        int n = prices.size();
        std::vector<int> dp(n + 1, 0);
        std::deque<int> q;

        for(int i = 0; i < n; i++)
        {
            while(!q.empty() && 
                    (q.front() + 1) * 2 < i + 1)q.pop_front();

            while(!q.empty() && 
                dp[q.back()] + prices[q.back()] >= 
                dp[i] + prices[i])q.pop_back();

            q.push_back(i);
            dp[i + 1] = dp[q.front()] + prices[q.front()];
        }
        return dp[n];
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> prices = {3,1,2};
        int res = 4;
        assert(sol.minimumCoins(prices) == res);
    }
    return 0;
}