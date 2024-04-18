#include <iostream>
#include <assert.h>

#include <vector>
#include <algorithm>

class Solution {
    const int mod = 1e9+7;
public:
    int maxSumRangeQuery(std::vector<int>& nums, 
                std::vector<std::vector<int>>& requests) {
        std::ios::sync_with_stdio(0);
        int n = nums.size();
        std::vector<int> cnt(n + 1);
        for(int i = 0; i < requests.size(); i++)
        {
            cnt[requests[i][0]]++;
            cnt[requests[i][1] + 1]--;
        }

        for(int i = 1; i <= n; i++)
        {
            cnt[i] += cnt[i - 1];
        }
        
        std::sort(cnt.begin(), cnt.end() - 1);
        std::sort(nums.begin(), nums.end());

        long long res = 0LL;
        for(int i = 0; i < n; i++)
        {
            res += 1LL * cnt[i] * nums[i];
            res %= mod;
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int>nums = {1,2,3,4,5};
        std::vector<std::vector<int>> requests = {{1,3},{0,1}};
        int res = 19;
        assert(sol.maxSumRangeQuery(nums, requests) == res);
    }
    return 0;
}