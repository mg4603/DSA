#include <iostream>
#include <assert.h>

#include <vector>
#include <algorithm>

class Solution {
public:
    int maxProduct(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int n = nums.size();
        return (nums[n - 1] - 1) * (nums[n - 2] - 1);
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> num = {3,4,5,2};
        int res = 12;
        assert(sol.maxProduct(num) == res);
    }
    {
        std::vector<int> num = {1,5,4,5};
        int res = 16;
        assert(sol.maxProduct(num) == res);
    }
    {
        std::vector<int> num = {3,7};
        int res = 12;
        assert(sol.maxProduct(num) == res);
    }
    return 0;
}