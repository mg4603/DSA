#include <iostream>
#include <assert.h>

#include <vector>
#include <numeric>
#include <limits>

class Solution {
public:
    int minimumAverageDifference(std::vector<int>& nums) {
        std::ios::sync_with_stdio(0);
        int n = nums.size();
        int res = 0;
        int min_avg_diff = std::numeric_limits<int>::max();
        long long post_sum = std::accumulate(nums.begin(), 
                                    nums.end(), 0LL);

        long long pre_sum = 0;
        for(int i = 0; i < n; i++)
        {
            pre_sum += nums[i];
            post_sum -= nums[i];
            int pre_avg = pre_sum / (i + 1);
            int post_avg = n - i - 1 > 0 ? post_sum / (n - i - 1) : 0;
            int temp = std::abs(pre_avg - post_avg);
            if(temp < min_avg_diff)
            {
                min_avg_diff = temp;
                res = i;
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {2,5,3,9,5,3};
        int res = 3;
        assert(sol.minimumAverageDifference(nums) == res);
    }
    return 0;
}