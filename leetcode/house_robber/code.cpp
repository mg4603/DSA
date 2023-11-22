#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
    int solve(std::vector<int> &nums, 
              std::vector<int> &table, int i)
    {
        if(i < 0)
        {
            return 0;
        }
        if(table[i] != -1)
        {
            return table[i];
        }
        table[i] = std::max(solve(nums, table, i - 2) + nums[i], 
                            solve(nums, table, i - 1));
        return table[i];
    }
public:
    int rob(std::vector<int>& nums) 
    {
        int n = nums.size();
        std::vector<int> table(n, -1);
        return solve(nums, table, n - 1);
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {1,2,3,1};
        int res = 4;
        assert(sol.rob(nums) == res);
    }
    {
        std::vector<int> nums = {2,7,9,3,1};
        int res = 12;
        assert(sol.rob(nums) == res);
    }
    return 0;
}