#include <iostream>
#include <assert.h>

#include <vector>
#include <numeric>

class Solution {
public:
    int minSizeSubarray(std::vector<int>& nums, int target) {
        long long total = std::accumulate(nums.begin(), 
                                        nums.end(), 0LL);
        int n = nums.size();
        int res_part = n;
        int res_full = n * (target / total);
        target %= total;

        long long runningSum = 0;
        int j = 0;
        for(int i = 0; i < 2 * n; i++)
        {
            runningSum += nums[i % n];
            while(runningSum > target)
            {
                runningSum -= nums[j % n];
                j++;
            }
            if(target == runningSum)
            {
                res_part = std::min(res_part, i - j + 1);
            }
        }
        return res_part == n ? -1 : res_part + res_full;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {1,2,3};
        int target = 5;
        int res = 2;
        assert(sol.minSizeSubarray(nums, target) == res);
    }
    return 0;
}