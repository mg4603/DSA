#include <iostream>
#include <assert.h>

#include <vector>
#include <unordered_map>

class Solution {
public:
    int maximumUniqueSubarray(std::vector<int>& nums) {
        std::unordered_map<int, int> mp;
        int j = 0;
        int n = nums.size();
        int res = 0;
        int runningSum = 0;

        for(int i = 0; i < n; i++)
        {
            runningSum += nums[i];
            if(mp.count(nums[i]))
            {
                while(mp[nums[i]] >= j)
                {
                    runningSum -= nums[j];
                    j++;
                }
            }
            mp[nums[i]] = i;
            res = std::max(runningSum, res);
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {4,2,4,5,6};
        int res = 17;
        assert(sol.maximumUniqueSubarray(nums) == res);
    }
    return 0;
}