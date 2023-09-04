#include <iostream>
#include <assert.h>

#include <vector>
#include <numeric>

class Solution {
public:
    double findMaxAverage(std::vector<int>& nums, int k) {
        double k_sum(std::accumulate(nums.begin(), nums.begin() + k, 0));
        double max_sum(k_sum);
        for(int i(1); i + k - 1 < nums.size(); i++)
        {
            k_sum -= nums[i - 1];
            k_sum += nums[i + k - 1];
            if(k_sum > max_sum)
            {
                max_sum = k_sum;
            }
        }

        return max_sum / static_cast<double>(k);
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {1,12,-5,-6,50,3};
        assert(sol.findMaxAverage(nums, 4) == 12.75000);
    }
    {
        std::vector<int> nums = {5};
        assert(sol.findMaxAverage(nums, 1) == 5.0);
    }
    return 0;
}