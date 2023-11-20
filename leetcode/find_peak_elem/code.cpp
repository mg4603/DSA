#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    int findPeakElement(std::vector<int>& nums) 
    {
        int n = nums.size();

        int l = 0;    
        int h = n - 1;
        while(l < h)
        {
            int mid = (l + h) / 2;
            if(nums[l] > nums[mid])
            {
                h = mid - 1;
            }
            else if(nums[h] > nums[mid])
            {
                l = mid + 1;
            }
            else
            {
                h--;
            }
        }
        return l;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {1,2,3,1};
        int res = 2;
        assert(sol.findPeakElement(nums) == res);
    }
    {
        std::vector<int> nums = {1,2,1,3,5,6,4};
        int res = 5;
        assert(sol.findPeakElement(nums) == res);
    }
    return 0;
}