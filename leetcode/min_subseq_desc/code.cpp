#include <iostream>
#include <assert.h>

#include <vector>
#include <algorithm>
#include <numeric>

class Solution {
public:
    std::vector<int> minSubsequence(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int sum1 = std::accumulate(nums.begin(), nums.end(), 0);

        std::vector<int> res;
        int sum2 = 0;
        for(int i = nums.size() - 1; i >= 0; i--)
        {
            sum1 -= nums[i];
            sum2 += nums[i];
            res.push_back(nums[i]);
            if(sum1 < sum2)
            {
                break;
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {4,3,10,9,8};
        std::vector<int> res = {10,9};
        assert(sol.minSubsequence(nums) == res);
    }
    {
        std::vector<int> nums = {4,4,7,6,7};
        std::vector<int> res = {7,7,6};
        assert(sol.minSubsequence(nums) == res);
    }
    return 0;
}