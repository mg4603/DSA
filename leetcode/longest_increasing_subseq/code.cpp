#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
    int solve(std::vector<int> &nums, 
              std::vector<int> &table, 
              int i, int prev_i)
    {
        if(i >= nums.size())
        {
            return 0;
        }
        if(table[prev_i + 1] != -1)return table[prev_i + 1];
        int take = 0;
        int dont_take = solve(nums, table, i + 1, prev_i);
        if(prev_i == - 1 || nums[i] > nums[prev_i])
        {
            take = 1 + solve(nums, table, i + 1, i);
        }
        table[prev_i + 1] = std::max(take, dont_take);
        return table[prev_i + 1];
    }
public:
    int lengthOfLIS(std::vector<int>& nums) 
    {
        std::vector<int> table(nums.size(), -1);
        return solve(nums, table, 0, -1);
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {10,9,2,5,3,7,101,18};
        int res = 4;
        assert(sol.lengthOfLIS(nums) == res);
    }
    {
        std::vector<int> nums = {0,1,0,3,2,3};
        int res = 4;
        assert(sol.lengthOfLIS(nums) == res);
    }
    {
        std::vector<int> nums = {7,7,7,7,7,7,7};
        int res = 1;
        assert(sol.lengthOfLIS(nums) == res);
    }
    return 0;
}