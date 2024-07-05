#include <iostream>
#include <assert.h>

#include <vector>
#include <algorithm>
#include <climits>

class Solution {
public:
    int findValueOfPartition(std::vector<int>& nums) {
        std::ios::sync_with_stdio(0);
        std::sort(nums.begin(), nums.end());
        int res = INT_MAX;
        for(int i = 1; i < nums.size(); i++) {
            res = std::min(res, nums[i] - nums[i - 1]);
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {1,3,2,4};
        int res = 1;
        assert(sol.findValueOfPartition(nums) == res);
    }
    return 0;
}