#include <iostream>
#include <assert.h>

#include <vector>
#include <algorithm>

class Solution {
public:
    int maximizeSum(std::vector<int>& nums, int k) 
    {
        int res = *std::max_element(nums.begin(), nums.end());
        return (res * k) + ((k - 1) * k / 2);
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {1,2,3,4,5};
        int k = 3;
        int res = 18;
        assert(sol.maximizeSum(nums, k) == res);
    }
    {
        std::vector<int> nums = {5,5,5};
        int k = 2;
        int res = 11;
        assert(sol.maximizeSum(nums, k) == res);
    }
    return 0;
}