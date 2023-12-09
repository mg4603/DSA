#include <iostream>
#include <assert.h>

#include <vector>
#include <numeric>

class Solution {
    bool helper(int target, std::vector<std::vector<int>> &table, 
                std::vector<int> &nums, int i)
    {
        if(target == 0)
        {
            return true;
        }

        if(i >= nums.size() || target < 0)
        {
            return false;
        }

        if(table[i][target] != -1)
        {
          return table[i][target];
        }

        bool take = helper(target - nums[i], table, nums, i + 1);
        bool dont_take = helper(target, table, nums, i + 1);
        table[i][target] = take || dont_take;
        return table[i][target];

    }
public:
    bool canPartition(std::vector<int>& nums) 
    {
        int n = nums.size();
        double half = std::accumulate(nums.begin(), 
                                nums.end(), 0) / 2.0;
        if(half != (int)half)
        {
            return false;
        }
        std::vector<std::vector<int>> table(n, 
                            std::vector<int>(half + 1, -1));

        return helper(half, table, nums, 0);
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {1,5,11,5};
        bool res = true;
        assert(sol.canPartition(nums) == res);
    }
    {
        std::vector<int> nums = {1,2,3,5};
        bool res = false;
        assert(sol.canPartition(nums) == res);
    }
    return 0;
}