#include <iostream>
#include <assert.h>

#include <vector>
#include <unordered_map>

class Solution {
public:
    int subarraySum(std::vector<int>& nums, int k) 
    {
        int n = nums.size();
        std::unordered_map<int, int> mp;
        int res = 0;

        mp[0] = 1;
        int r_sum = 0;

        for(int i = 0; i < n; i++)
        {
            r_sum += nums[i];
            if(mp.count(r_sum - k))
            {
                res += mp[r_sum - k];
            }
            mp[r_sum]++;
        }

        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {1,1,1};
        int k = 2;
        int res = 2;
        assert(sol.subarraySum(nums, k) == res);
    }
    {
        std::vector<int> nums = {1,2,3};
        int k = 3;
        int res = 2;
        assert(sol.subarraySum(nums, k) == res);
    }
    return 0;
}