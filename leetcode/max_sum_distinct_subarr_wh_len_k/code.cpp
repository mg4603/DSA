#include <iostream>
#include <assert.h>

#include <vector>
#include <unordered_map>

class Solution {
public:
    long long maximumSubarraySum(std::vector<int>& nums, int k) {
        int n = nums.size();
        long long res = 0;
        long long sum = 0;
        std::unordered_map<int, int> mp;
        int j = -1;

        for(int i = 0; i < n; i++)
        {
            sum += nums[i];
            if(i >= k)sum -= nums[i - k];
            
            if(mp.count(nums[i]))j = std::max(j, mp[nums[i]]);
            if(i - j >= k)res = std::max(res, sum);
            mp[nums[i]] = i;
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {1,5,4,2,9,9,9};
        int k = 3;
        int res = 15;
        assert(sol.maximumSubarraySum(nums, k) == res);
    }
    return 0;
}