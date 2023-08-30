#include <iostream>
#include <assert.h>

#include <vector>
#include <algorithm>

class Solution {
public:
    int missingNumber(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int idx(0);
        for(int i(0); i <= nums.back(); i++)
        {
            if(nums[idx++] != i)
            {
                return i;
            }
        }
        return nums.back() + 1;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {3,0,1};
        assert(sol.missingNumber(nums) == 2);
    }
    {
        std::vector<int> nums = {0, 1};
        assert(sol.missingNumber(nums) == 2);
    }
    {
        std::vector<int> nums = {9,6,4,2,3,5,7,0,1};
        assert(sol.missingNumber(nums) == 8);
    }
    return 0;
}