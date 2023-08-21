#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    int searchInsert(std::vector<int>& nums, int target) {
        if(nums.size() == 0)
        {
            return 0;
        }
        else if(target < nums[0])
        {
            return 0;
        }
        else if(target > nums.back())
        {
            return nums.size();
        }
        
        int low(0);
        int high(nums.size() - 1);
        while(low <= high)
        {
            int mid((low + high) /2 );
            if(nums[mid] < target)
            {
                low = mid + 1;
            }
            else if(nums[mid] > target)
            {
                high = mid - 1;
            }
            else
            {
                return mid;
            }
        }
        return low;
    }
};

int main()
{
    std::vector<int> vec{1,3,5,6};

    Solution sol;
    {
        assert(sol.searchInsert(vec, 5) == 2);
        assert(sol.searchInsert(vec, 2) == 1);
        assert(sol.searchInsert(vec, 7) == 4);
    }
    return 0;
}