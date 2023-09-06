#include <iostream>
#include <assert.h>

#include <vector>
#include <algorithm>

class Solution {
public:
    int maximumProduct(std::vector<int>& nums) {
        if(nums.size() == 3)
        {
            return nums[0] * nums[1] * nums[2];
        }
        std::sort(nums.begin(), nums.end());
        int negatives(0);
        for(int num: nums)
        {
            if(num < 0)
            {
                negatives++;
            }
        }
        int n = nums.size();
        int left = nums[0] * nums[1];
        return std::max(left * nums.back() , nums[n - 1] * nums[n - 2] * nums[n - 3]);
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {1,2,3};
        assert(sol.maximumProduct(nums) == 6);
    }
    {
        std::vector<int> nums = {1,2,3,4};
        assert(sol.maximumProduct(nums) == 24);
    }
    {
        std::vector<int> nums = {-1,-2,-3};
        assert(sol.maximumProduct(nums) == -6);
    }
    return 0;
}