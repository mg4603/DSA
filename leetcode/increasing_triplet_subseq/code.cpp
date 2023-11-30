#include <iostream>
#include <assert.h>

#include <vector>
#include <limits>

class Solution {
public:
    bool increasingTriplet(std::vector<int>& nums) 
    {
        int small = std::numeric_limits<int>::max();
        int mid = std::numeric_limits<int>::max();

        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] <= small)
            {
                small = nums[i];
            }
            else if(nums[i] <= mid)
            {
                mid = nums[i];
            }
            else
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
        std::vector<int> nums = {1,2,3,4,5};
        bool res = true;
        assert(sol.increasingTriplet(nums) == res);
    }
    {
        std::vector<int> nums = {5,4,3,2,1};
        bool res = false;
        assert(sol.increasingTriplet(nums) == res);
    }
    {
        std::vector<int> nums = {2,1,5,0,4,6};
        bool res = true;
        assert(sol.increasingTriplet(nums) == res);
    }
    return 0;
}