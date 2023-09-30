#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    bool isMonotonic(std::vector<int>& nums) {
        if(nums.size() < 2)
        {
            return true;
        }
        int inc(0);

        for(int i(1); i < nums.size(); i++)
        {
            if(inc)
            {
                if(inc == 1 && nums[i] > nums[i - 1])
                {
                    return false;
                }
                else if(inc == -1 && nums[i] < nums[i - 1])
                {
                    return false;
                }
            }
            else
            {
                if(nums[i] < nums[i - 1])
                {
                    inc = 1;
                }
                else if(nums[i] > nums[i - 1])
                {
                    inc = -1;
                }
            }
        }
        return true;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {1,2,2,3};
        assert(sol.isMonotonic(nums) == true);
    }
    {
        std::vector<int> nums = {6,5,4,4};
        assert(sol.isMonotonic(nums) == true);
    }
    {
        std::vector<int> nums = {1,3,2};
        assert(sol.isMonotonic(nums) == false);
    }
    return 0;
}