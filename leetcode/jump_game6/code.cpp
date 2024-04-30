#include <iostream>
#include <assert.h>

#include <vector>
#include <deque>
#include <climits>

class Solution {
public:
    int maxResult(std::vector<int>& nums, int k) {
        std::ios::sync_with_stdio(0);
        int n = nums.size();
        std::vector<int> dp(n, INT_MIN);
        dp[0] = nums[0];
        std::deque<int> q{0};

        for(int i = 1; i < n; i++)
        {
            while(!q.empty() && q.front() < i - k)q.pop_front();
            dp[i] = nums[i] + dp[q.front()];
            while(!q.empty() && dp[q.back()] <= dp[i])q.pop_back();
            q.push_back(i);
        }
        return dp[n - 1];
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {1,-1,-2,4,-7,3};
        int k = 2;
        int res = 7;
        assert(sol.maxResult(nums, k) == res);
    }
    return 0;
}