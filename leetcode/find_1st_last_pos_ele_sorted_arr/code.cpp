#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
    int binarySearch(std::vector<int> &nums, int target)
    {
        int l = 0;
        int h = nums.size() - 1;
        while(l <= h)
        {
            int mid = (l + h) / 2;
            if(nums[mid] == target)
            {
                return mid;
            }
            if(nums[mid] < target)
            {
                l = mid + 1;
            }
            if(nums[mid] > target)
            {
                h = mid - 1;
            }
        }
        return -1;
    }
public:
    std::vector<int> searchRange(std::vector<int>& nums, int target) 
    {
        int pos = binarySearch(nums, target);
        
        if(pos == -1)
        {
            return {-1, -1};
        }
        
        int first = pos;
        int last = pos;
        
        while(first - 1 >= 0 && nums[first - 1] == nums[pos])
        {
            first--;
        }
        while(last + 1 < nums.size() && nums[last + 1] == nums[pos])
        {
            last++;
        }
        return {first, last};
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {5,7,7,8,8,10};
        int target = 8;
        std::vector<int> res = {3, 4};
        assert(sol.searchRange(nums, target) == res);
    }
    {
        std::vector<int> nums = {5,7,7,8,8,10};
        int target = 6;
        std::vector<int> res = {-1, -1};
        assert(sol.searchRange(nums, target) == res);
    }
    {
        std::vector<int> nums = {};
        int target = 0;
        std::vector<int> res = {-1,-1};
        assert(sol.searchRange(nums, target) == res);
    }
    return 0;
}