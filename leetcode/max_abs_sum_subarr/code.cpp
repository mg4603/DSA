#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    int maxAbsoluteSum(std::vector<int>& nums) {
        std::ios::sync_with_stdio(0);
        int maxi = 0;
        int mini = 0;
        int runningSum = 0;
        for(int &num: nums) {
            runningSum += num;
            maxi = std::max(maxi, runningSum);
            mini = std::min(mini, runningSum);
        }
        return maxi - mini;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {1,-3,2,3,-4};
        int res = 5;
        assert(sol.maxAbsoluteSum(nums) == res);
    }
    return 0;
}