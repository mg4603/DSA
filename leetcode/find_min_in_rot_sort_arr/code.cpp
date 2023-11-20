#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    int findMin(std::vector<int>& nums) 
    {
        int n = nums.size();

        int l = 0;
        int h = n - 1;

        while(l < h)
        {
            int mid = (l + h) / 2;
            
            if(nums[h] > nums[mid])
            {
                h = mid;
            }
            else if(nums[h] < nums[mid])
            {
                l = mid + 1;
            }
        }

        return nums[l];
        
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {3,4,5,1,2};
        int res = 1;
        assert(sol.findMin(nums) == res);
    }
    {
        std::vector<int> nums = {4,5,6,7,0,1,2};
        int res = 0;
        assert(sol.findMin(nums) == res);
    }
    {
        std::vector<int> nums = {11,13,15,17};
        int res = 11;
        assert(sol.findMin(nums) == res);
    }
    return 0;
}