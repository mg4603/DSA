#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    int search(std::vector<int>& nums, int target) 
    {
        int n = nums.size();
        int l = 0;
        int h = n - 1;

        while(l <= h)
        {
            int mid = (l + h) / 2;
            if(target == nums[mid])
            {
                return mid;
            }
            if(nums[l] <= nums[mid])
            {
                if(nums[l] <= target && target < nums[mid])
                {
                    h = mid - 1;
                }
                else
                {
                    l = mid + 1;
                }
            }
            else
            {
                if(nums[mid] < target  && target <= nums[h])
                {
                    l = mid + 1;
                }
                else
                {
                    h = mid - 1;
                }
            }
        }
        return -1;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {4,5,6,7,0,1,2};
        int target = 0;
        int res = 4;
        assert(sol.search(nums, target) == res);
    }
    {
        std::vector<int> nums = {4,5,6,7,0,1,2};
        int target = 3;
        int res = -1;
        assert(sol.search(nums, target) == res);
    }
    {
        std::vector<int> nums = {1};
        int target = 0;
        int res = -1;
        assert(sol.search(nums, target) == res);
    }
    return 0;
}