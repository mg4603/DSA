#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    int search(std::vector<int>& nums, int target) {
        int low(0);
        int high(nums.size() - 1);
        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            if(target == nums[mid])
            {
                return mid;
            }
            else if(target > nums[mid])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return -1;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {-1,0,3,5,9,12};
        int target = 9;
        assert(sol.search(nums, target) == 4);
    }
    {
        std::vector<int> nums = {-1,0,3,5,9,12};
        int target = 2;
        assert(sol.search(nums, target) == -1);
    }
    return 0;
}