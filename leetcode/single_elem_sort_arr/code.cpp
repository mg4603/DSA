#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    int singleNonDuplicate(std::vector<int>& nums) 
    {
        int l = 0;
        int r = nums.size() - 1;
        while(l < r)
        {
            int mid = (l + r) / 2;
            
            if(mid % 2 == 1)
            {
                mid--;
            }
            if(nums[mid] != nums[mid + 1])
            {
                r = mid;
            }
            else
            {
                l = mid + 2;
            }

        }
        return nums[l];
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {1,1,2,3,3,4,4,8,8};
        int res = 2;
        assert(sol.singleNonDuplicate(nums) == res);
    }
    {
        std::vector<int> nums = {3,3,7,7,10,11,11};
        int res = 10;
        assert(sol.singleNonDuplicate(nums) == res);
    }
    return 0;
}