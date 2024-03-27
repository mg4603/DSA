#include <iostream>
#include <assert.h>

#include <vector>
#include <unordered_map>
#include <climits>

class Solution {
public:
    long long maximumSubarraySum(std::vector<int>& nums, int k) {
        int n = nums.size();
        std::vector<long long> prefix(n + 1, 0LL);

        std::unordered_map<int, int> mp;
        long long res = LLONG_MIN;

        for(int i = 0; i < n; i++)
        {
            prefix[i + 1] = prefix[i] + nums[i];
            if(mp.count(nums[i] - k))
            {
                res = std::max(res, 
                        prefix[i + 1] - prefix[mp[nums[i] - k]]);
            }
            if(mp.count(nums[i] + k))
            {
                res = std::max(res, 
                        prefix[i + 1] - prefix[mp[nums[i] + k]]);
            }
            if(!mp.count(nums[i]) || 
                prefix[i] - prefix[mp[nums[i]]] <= 0)
            {
                mp[nums[i]] = i;
            }
        }
        return res == LLONG_MIN ? 0 : res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {1,2,3,4,5,6};
        int k = 1;
        int res = 11;
        assert(sol.maximumSubarraySum(nums, k) == res);
    }
    return 0;
}