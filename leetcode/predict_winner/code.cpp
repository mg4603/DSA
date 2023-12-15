#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
    int helper(std::vector<std::vector<int>> &table,
               std::vector<int> &nums, int l, int r)
    {
        if(l == r)
        {
            return nums[l];
        }
        if(table[l][r] != -1)
        {
            return table[l][r];
        }

        int left = nums[l] - helper(table, nums, l + 1, r);
        int right = nums[r] - helper(table, nums, l, r - 1);
        table[l][r] = std::max(left, right);
        return table[l][r];
    }
public:
    bool predictTheWinner(std::vector<int>& nums) 
    {
        int n = nums.size();
        std::vector<std::vector<int>> table(n, 
                                std::vector<int>(n, -1));
        return helper(table, nums, 0, n - 1) >= 0;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {1,5,2};
        bool res = false;
        assert(sol.predictTheWinner(nums) == res);
    }
    {
        std::vector<int> nums = {1,5,233,7};
        bool res = true;
        assert(sol.predictTheWinner(nums) == res);
    }
    return 0;
}