#include <iostream>
#include <assert.h>

#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<int> applyOperations(std::vector<int>& nums) 
    {
        for(int i = 0; i < nums.size() - 1; i++)
        {
            if(nums[i] == nums[i + 1])
            {
                nums[i] *= 2;
                nums[i + 1] = 0;
            }
        }
        
        auto it = std::remove(nums.begin(), nums.end(), 0);
        for(; it != nums.end(); it++)
        {
            *it = 0;
        }
        return nums;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {1,2,2,1,1,0};
        std::vector<int> res = {1,4,2,0,0,0};
        assert(sol.applyOperations(nums) == res);
    }
    {
        std::vector<int> nums = {0,1};
        std::vector<int> res = {1,0};
        assert(sol.applyOperations(nums) == res);
    }
    return 0;
}