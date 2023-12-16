#include <iostream>
#include <assert.h>

#include <vector>
#include <limits>
#include <numeric>

class Solution {
    int total;
    int target;

    int helper(std::vector<std::vector<int>> &table, 
               std::vector<int> &nums, int i, int sum)
    {
        if(i == nums.size())
        {
            if(target == sum)
            {
                return 1;
            }
            return 0;
        }

        if(table[i][sum + total] != std::numeric_limits<int>::min())
        {
            return table[i][total + sum];
        }

        int add = helper(table, nums, i + 1, sum + nums[i]);
        int sub = helper(table, nums, i + 1, sum - nums[i]);
        table[i][total + sum] = add + sub;
        return table[i][total + sum ];
    }
public:
    int findTargetSumWays(std::vector<int>& nums, int target) 
    {
        int n = nums.size();
        total = std::accumulate(nums.begin(), nums.end(), 0);
        this->target = target;
        
        std::vector<std::vector<int>> table(n + 1, 
                                    std::vector<int>(2 * total + 1, 
                                    std::numeric_limits<int>::min()));

        return helper(table, nums, 0, 0);
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {1,1,1,1,1};
        int target = 3;
        int res = 5;
        assert(sol.findTargetSumWays(nums, target) == res);
    }
    {
        std::vector<int> nums = {1};
        int target = 1;
        int res = 1;
        assert(sol.findTargetSumWays(nums, target) == res);
    }
    return 0;
}