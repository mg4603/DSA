#include <iostream>
#include <assert.h>

#include <algorithm>
#include <vector>

class Solution {
public:
    std::vector<int> findDuplicates(std::vector<int>& nums) 
    {
        std::sort(nums.begin(), nums.end());
        std::vector<int> res;

        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i] == nums[i - 1])
            {
                res.push_back(nums[i]);
                i++;
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {4,3,2,7,8,2,3,1};
        std::vector<int> res = {2,3};
        assert(sol.findDuplicates(nums) == res);
    }
    {
        std::vector<int> nums = {1,1,2};
        std::vector<int> res = {1};
        assert(sol.findDuplicates(nums) == res);
    }
    {
        std::vector<int> nums = {};
        std::vector<int> res = {};
        assert(sol.findDuplicates(nums) == res);
    }
    return 0;
}