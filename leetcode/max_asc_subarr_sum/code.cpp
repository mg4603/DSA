#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    int maxAscendingSum(std::vector<int>& nums) 
    {
        int res = 0;
        int current = nums[0];
        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i] > nums[i - 1])
            {
                current += nums[i];
            }
            else
            {
                if(current > res)
                {
                    res = current;
                }
                current = nums[i];
            }
        }
        return std::max(res, current);
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {10,20,30,5,10,50};
        int res = 65;
        assert(sol.maxAscendingSum(nums) == res);
    }
    {
        std::vector<int> nums = {10,20,30,40,50};
        int res = 150;
        assert(sol.maxAscendingSum(nums) == res);
    }
    {
        std::vector<int> nums = {12,17,15,13,10,11,12};
        int res = 33;
        assert(sol.maxAscendingSum(nums) == res);
    }
    return 0;
}