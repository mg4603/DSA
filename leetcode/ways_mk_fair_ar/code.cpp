#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    int waysToMakeFair(std::vector<int>& nums) {
        std::ios::sync_with_stdio(0);
        int n = nums.size();
        std::vector<int> right(2, 0);
        std::vector<int> left(2, 0);
        for(int i = 0; i < n; i++)
        {
            right[i % 2] += nums[i];
        }
        int res = 0;
        for(int i = 0; i < n; i++)
        {
            right[i % 2] -= nums[i];
            res += left[1] + right[0] == left[0] + right[1];
            left[i % 2] += nums[i];
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {2,1,6,4};
        int res = 1;
        assert(sol.waysToMakeFair(nums) == res);
    }
    return 0;
}