#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    int combinationSum4(std::vector<int>& nums, int target)
    {
        std::vector<unsigned> table(target + 1, 0);
        table[0] = 1;

        for(int i = 1; i <= target; i++)
        {
            for(int j = 0; j < nums.size(); j++)
            {
                if(i >= nums[j])
                {
                    table[i] += table[i - nums[j]];
                }
            }
        }
        return table[target];
    }   
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {1,2,3};
        int target = 4;
        int res = 7;
        assert(sol.combinationSum4(nums, target) == res);
    }
    {
        std::vector<int> nums = {9};
        int target = 3;
        int res = 0;
        assert(sol.combinationSum4(nums, target) == res);
    }
    return 0;
}