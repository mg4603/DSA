#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    int minimumRightShifts(std::vector<int>& nums) 
    {
        int dec = 0;
        int res = 0;
        int n = nums.size();

        for(int i = 0; i < n; i++)
        {
            if(nums[(i + 1) % n] < nums[i])
            {
                dec++;
                res = n - i - 1;
            }
            if(dec > 1)
            {
                return -1;
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {3,4,5,1,2};
        int res = 2;
        assert(sol.minimumRightShifts(nums) == res);
    }
    {
        std::vector<int> nums = {1,3,5};
        int res = 0;
        assert(sol.minimumRightShifts(nums) == res);
    }
    {
        std::vector<int> nums = {2,1,4};
        int res = -1;
        assert(sol.minimumRightShifts(nums) == res);
    }
    return 0;
}