#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
    bool binarySearch(std::vector<int> &nums, int low, int high, int target, int pivot = -1)
    {
        
        int l = low;
        int h = high;
        if(pivot != -1 && pivot != low)
        {
            if(nums[l] > target)
            {
                l = pivot;
            }
            else
            {
                h = pivot - 1;
            }
        }

        while(l <= h)
        {
            int mid = (l + h) / 2;
            if(nums[mid] == target)
            {
                return true;
            }
            else if(nums[mid] > target)
            {
                h = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        return false;
    }
public:
    bool search(std::vector<int>& nums, int target) 
    {
        int n = nums.size();

        int l = 0; 
        int h = n - 1;

        while(l + 1 < n && nums[l] == nums[l + 1])l++;

        if(l == h)
        {
            return (nums[0] == target);
        }

        while(h >= 0 && nums[h] == nums[0])
        {
            h--;
        }

        int pivot = -1;

        int low = l;
        int high = h;

        while(l <= h)
        {
            int mid = (l + h) / 2;
            if(nums[mid] >= nums[0])
            {
                l = mid + 1;
            }
            else
            {
                pivot = mid;
                h = mid - 1;
            }
        }
        return binarySearch(nums, low, high, target, pivot);
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {2,5,6,0,0,1,2};
        int target = 0;
        bool res = true;
        assert(sol.search(nums, target) == res);
    }
    {
        std::vector<int> nums = {2,5,6,0,0,1,2};
        int target = 3;
        bool res = false;
        assert(sol.search(nums, target) == res);
    }
    return 0;
}