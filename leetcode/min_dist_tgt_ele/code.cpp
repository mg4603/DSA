#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    int getMinDistance(std::vector<int>& nums, int target, int start) 
    {
        int i = 0;
        while(start + i < nums.size() || start - i >= 0)
        {
            if((start + i < nums.size() && nums[start + i] == target) ||
                (start - i >= 0 && nums[start - i] == target))
            {
                return i;
            }
            i++;
        }
        return -1;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {1,2,3,4,5};
        int target = 5;
        int start = 3;
        int res = 1;
        assert(sol.getMinDistance(nums, target, start) == res);
    }
    {
        std::vector<int> nums = {1};
        int target = 1;
        int start = 0;
        int res = 0;
        assert(sol.getMinDistance(nums, target, start) == res);
    }
    {
        std::vector<int> nums = {1,1,1,1,1,1,1,1,1,1};
        int target = 1;
        int start = 0;
        int res = 0;
        assert(sol.getMinDistance(nums, target, start) == res);
    }
    return 0;
}