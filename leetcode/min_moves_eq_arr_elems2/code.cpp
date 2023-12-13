#include <iostream>
#include <assert.h>

#include <vector>
#include <algorithm>

class Solution {
public:
    int minMoves2(std::vector<int>& nums) 
    {
        int n = nums.size();
        std::sort(nums.begin(), nums.end());
        int median = nums[n/2];
        int res = 0;
        for(int i = 0; i < n; i++)
        {
            res += std::abs(median - nums[i]);
        }
        return res;  
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {1,2,3};
        int res = 2;
        assert(sol.minMoves2(nums) == res);
    }
    {
        std::vector<int> nums = {1,10,2,9};
        int res = 16;
        assert(sol.minMoves2(nums) == res);
    }
    return 0;
}