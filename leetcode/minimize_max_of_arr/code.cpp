#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    int minimizeArrayValue(std::vector<int>& nums) {
        std::ios::sync_with_stdio(0);
        int n = nums.size();
        long long res = 0LL;
        long long runningSum = 0LL;
        for(int i = 0; i < n; i++)
        {
            runningSum += nums[i];
            res = std::max(res, (runningSum + i) / (i + 1));
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {3,7,1,6};
        int res = 5;
        assert(sol.minimizeArrayValue(nums) == res);
    }
    return 0;
}