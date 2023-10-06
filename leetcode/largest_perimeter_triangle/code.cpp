#include <iostream>
#include <assert.h>

#include <vector>
#include <algorithm>

class Solution {
public:
    int largestPerimeter(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        for(int i = nums.size() - 1; i >= 2; i--)
        {
            if(nums[i] < nums[i - 1] + nums[i - 2])
            {
                return nums[i] + nums[i - 1] + nums[i - 2];
            }
        }
        return 0;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {2,1,2};
        int res = 5;
        assert(sol.largestPerimeter(nums) == res);
    }
    {
        std::vector<int> nums = {1,2,1,10};
        int res = 0;
        assert(sol.largestPerimeter(nums) == res);
    }
    return 0;
}