#include <iostream>
#include <assert.h>

#include <vector>
#include <unordered_map>

class Solution {
public:
    bool checkSubarraySum(std::vector<int>& nums, int k) 
    {
        int n = nums.size();
        if(n < 2)
        {
            return false;
        }
        std::unordered_map<int, int> mp;
        mp[0] = -1;

        int sum = 0;
        for(int i = 0; i < n; i++)
        {
            sum += nums[i];
            sum %= k;

            if(mp.count(sum) == 0)
            {
                mp[sum] = i;
            }
            int prev = mp[sum];
            if(i > prev + 1)
            {
                return true;
            }
        }
        return false;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {23,2,4,6,7};
        int k = 6;
        bool res = true;
        assert(sol.checkSubarraySum(nums, k) == res);
    }
    {
        std::vector<int> nums = {23,2,6,4,7};
        int k = 6;
        bool res = true;
        assert(sol.checkSubarraySum(nums, k) == res);
    }
    {
        std::vector<int> nums = {23,2,4,6,7};
        int k = 13;
        bool res = true;
        assert(sol.checkSubarraySum(nums, k) == res);
    }
    return 0;
}