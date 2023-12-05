#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    int wiggleMaxLength(std::vector<int>& nums) 
    {
        int peaks = 1; 
        int valleys = 1;
        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i] < nums[i - 1])
            {
                valleys = peaks + 1;
            }
            if(nums[i] > nums[i - 1])
            {
                peaks = valleys + 1;
            }
        }
        return std::max(peaks, valleys);
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {1,7,4,9,2,5};
        int res = 6;
        assert(sol.wiggleMaxLength(nums) == res);
    }
    {
        std::vector<int> nums = {1,17,5,10,13,15,10,5,16,8};
        int res = 7;
        assert(sol.wiggleMaxLength(nums) == res);
    }
    {
        std::vector<int> nums = {1,2,3,4,5,6,7,8,9};
        int res = 2;
        assert(sol.wiggleMaxLength(nums) == res);
    }
    return 0;
}