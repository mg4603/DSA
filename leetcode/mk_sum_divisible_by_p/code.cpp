#include <iostream>
#include <assert.h>

#include <vector>
#include <numeric>
#include <unordered_map>

class Solution {
public:
    int minSubarray(std::vector<int>& nums, int p) {
        std::ios::sync_with_stdio(0);
        int n = nums.size();
        int target = std::accumulate(nums.begin(), 
                            nums.end(), 0LL) % p;

        if(target == 0)return 0;

        std::unordered_map<int, int> mp;
        mp[0] = -1;
        long long preSum = 0LL;
        int res = n;

        for(int i = 0; i < n; i++)
        {
            preSum += nums[i];
            int key = (preSum % p - target + p) % p;

            if(mp.count(key))
            {
                res = std::min(res, i - mp[key]);
            }
            mp[preSum % p] = i;
        }

        return res < n ? res : -1;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {3,1,4,2};
        int p = 6;
        int res = 1;
        assert(sol.minSubarray(nums, p) == res);
    }
    return 0;
}