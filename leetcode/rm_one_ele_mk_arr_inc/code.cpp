#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
    bool isIncreasing(std::vector<int> &nums, int skip)
    {
        int prev = nums[0];
        int i = 1;
        if(skip == 0)
        {
            prev = nums[1];
            i = 2;
        }
        for(; i < nums.size(); i++)
        {
            if(i == skip)continue;
            if(nums[i] <= prev)
            {
                return false;
            }
            prev = nums[i];
        }
        return true;
    }
public:
    bool canBeIncreasing(std::vector<int>& nums) {
        int decreasing = 0;
        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i] > nums[i - 1])continue;
            return isIncreasing(nums, i- 1) || isIncreasing(nums, i);
        }
        return true;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {1,2,10,5,7};
        bool res = true;
        assert(sol.canBeIncreasing(nums) == res);
    }
    {
        std::vector<int> nums = {2,3,1,2};
        bool res = false;
        assert(sol.canBeIncreasing(nums) == res);
    }
    {
        std::vector<int> nums = {1,1,1};
        bool res = false;
        assert(sol.canBeIncreasing(nums) == res);
    }
    return 0;
}