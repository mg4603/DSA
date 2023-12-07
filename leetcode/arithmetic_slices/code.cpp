#include <iostream>
#include <assert.h>

#include <numeric>
#include <vector>

class Solution {
public:
    int numberOfArithmeticSlices(std::vector<int>& nums) 
    {
        int n = nums.size();
        if(n < 3)
        {
            return 0;
        }
        std::vector<int> table(n, 0);

        for(int i = 2; i < n; i++)
        {
            if(nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2])
            {
                table[i] = table[i - 1] + 1;
            }
        }
        
        return std::accumulate(table.begin(), table.end(), 0);
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {1,2,3,4};
        int res = 3;
        assert(sol.numberOfArithmeticSlices(nums) == res);
    }
    {
        std::vector<int> nums = {1};
        int res = 0;
        assert(sol.numberOfArithmeticSlices(nums) == res);
    }
    return 0;
}