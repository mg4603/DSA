#include <iostream>
#include <assert.h>

#include <vector>
#include <limits>

class Solution {
public:
    int maxSubArray(std::vector<int>& nums) 
    {
        int res = std::numeric_limits<int>::min();

        int curr = nums[0];
        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i] > curr + nums[i])
            {
                if(curr > res)
                {
                    res = curr;
                }
                curr = nums[i];
            }
            else
            {
                if(curr > res)
                {
                    res = curr;
                }
                curr += nums[i];
            }
        }

        return std::max(curr, res);
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
        int res = 6;
        assert(sol.maxSubArray(nums) == res);
    }
    {
        std::vector<int> nums = {1};
        int res = 1;
        assert(sol.maxSubArray(nums) == res);
    }
    {
        std::vector<int> nums = {5,4,-1,7,8};
        int res = 23;
        assert(sol.maxSubArray(nums) == res);
    }
    return 0;
}