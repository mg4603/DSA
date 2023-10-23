#include <iostream>
#include <assert.h>

#include <vector>
#include <algorithm>

class Solution {
public:
    int maxProductDifference(std::vector<int>& nums) 
    {
        std::sort(nums.begin(), nums.end());
        int n = nums.size();
        return (nums[n - 1] * nums[n - 2]) - (nums[0] * nums[1]);
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {5,6,2,7,4};
        int res = 34;
        assert(sol.maxProductDifference(nums) == res);
    }
    {
        std::vector<int> nums = {4,2,5,9,7,4,8};
        int res = 64;
        assert(sol.maxProductDifference(nums) == res);
    }
    return 0;
}