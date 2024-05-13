#include <iostream>
#include <assert.h>

#include <vector>
#include <algorithm>
#include <climits>

class Solution {
public:
    int minPairSum(std::vector<int>& nums) {
        std::ios::sync_with_stdio(0);
        std::sort(nums.begin(), nums.end());
        int res = INT_MIN;
        int n = nums.size();
        for(int i = 0; i < n / 2; i++) {
            res = std::max(res, nums[i] + nums[n - i - 1]);
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {3,5,2,3};
        int res = 7;
        assert(sol.minPairSum(nums) == res);
    }
    return 0;
}