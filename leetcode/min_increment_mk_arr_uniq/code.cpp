#include <iostream>
#include <assert.h>

#include <vector>
#include <algorithm>

class Solution {
public:
    int minIncrementForUnique(std::vector<int>& nums) {
        std::ios::sync_with_stdio(0);
        int res = 0;
        std::sort(nums.begin(), nums.end());
        int temp = nums[0];
        for(int &num: nums) {
            res += std::max(temp - num, 0);
            temp = std::max(temp, num) + 1;
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {1,2,2};
        int res = 1;
        assert(sol.minIncrementForUnique(nums) == res);
    }
    return 0;
}