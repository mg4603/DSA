#include <iostream>
#include <assert.h>

#include <vector>
#include <cmath>
#include <numeric>
#include <algorithm>

class Solution {
public:
    int largestSumAfterKNegations(std::vector<int>& nums, int k) {
        std::sort(nums.begin(), nums.end());

        int i(0);
        while(k > 0 && i < nums.size() && nums[i] < 0 )
        {
            nums[i] = -nums[i];
            k--;
            i++;
        }
        
        if(k > 0)
        {
            std::sort(nums.begin(), nums.end());
            nums[0] = std::pow(-1, k) * nums[0];
        }
        return std::accumulate(nums.begin(), nums.end(), 0);
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {4,2,3};
        int k = 1;
        int res = 5;
        assert(sol.largestSumAfterKNegations(nums, k) == res);
    }
    {
        std::vector<int> nums = {3,-1,0,2};
        int k = 3;
        int res = 6;
        assert(sol.largestSumAfterKNegations(nums, k) == res);
    }
    {
        std::vector<int> nums = {2,-3,-1,5,-4};
        int k = 2;
        int res = 13;
        assert(sol.largestSumAfterKNegations(nums, k) == res);
    }
    return 0;
}