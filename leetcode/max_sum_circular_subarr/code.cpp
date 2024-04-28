#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    int maxSubarraySumCircular(std::vector<int>& nums) {
        std::ios::sync_with_stdio(0);
        int total = 0;
        int max_sum = nums[0];
        int curr_max = 0;
        int curr_min = 0;
        int min_sum = nums[0];
        int n = nums.size();
        for(int i = 0; i < n; i++)
        {
            int num = nums[i];

            curr_max = std::max(curr_max + num, num);
            curr_min = std::min(curr_min + num, num);
            max_sum = std::max(max_sum, curr_max);
            min_sum = std::min(curr_min, min_sum);
            total += num;
        }
        return max_sum > 0 ? std::max(max_sum, total - min_sum) : max_sum;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {1,-2,3,-2};
        int res = 3;
        assert(sol.maxSubarraySumCircular(nums) == res);
    }
    return 0;
}