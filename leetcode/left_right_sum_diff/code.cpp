#include <iostream>
#include <assert.h>

#include <vector>
#include <numeric>

class Solution {
public:
    std::vector<int> leftRightDifference(std::vector<int>& nums) 
    {
        int left = 0;
        int right = std::accumulate(nums.begin(), nums.end(), 0);
        for(int i = 0; i < nums.size(); i++)
        {
            int temp = nums[i];
            right -= temp;
            nums[i] = std::abs(right - left);
            left += temp;
        }    
        return nums;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {10,4,8,3};
        std::vector<int> res = {15,1,11,22};
        assert(sol.leftRightDifference(nums) == res);
    }
    {
        std::vector<int> nums = {1};
        std::vector<int> res = {0};
        assert(sol.leftRightDifference(nums) == res);
    }
    return 0;
}