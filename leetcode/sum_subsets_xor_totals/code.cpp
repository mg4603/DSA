#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
    int helper(std::vector<int> &nums, int i, int currentRes)
    {
        if(i == nums.size()) return currentRes;

        int withElement = helper(nums, i + 1, currentRes ^ nums[i]);
        int withoutElement = helper(nums, i + 1, currentRes);
        return withElement + withoutElement;
    }
public:
    int subsetXORSum(std::vector<int>& nums) {
        return helper(nums, 0, 0);
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {1,3};
        int res = 6;
        assert(sol.subsetXORSum(nums) == res);
    }
    {
        std::vector<int> nums = {5,1,6};
        int res = 28;
        assert(sol.subsetXORSum(nums) == res);
    }
    {
        std::vector<int> nums = {3,4,5,6,7,8};
        int res = 480;
        assert(sol.subsetXORSum(nums) == res);
    }
    return 0;
}