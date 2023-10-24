#include <iostream>
#include <assert.h>

#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<int> targetIndices(std::vector<int>& nums, int target) {
        std::vector<int> res;
        std::sort(nums.begin(), nums.end());
        int start = std::find(nums.begin(), nums.end(), target) - nums.begin();
        for(int i = start; i < nums.size() && nums[i] == target; i++)
        {
            res.push_back(i);
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {1,2,5,2,3};
        int target = 2;
        std::vector<int> res = {1,2};
        assert(sol.targetIndices(nums, target) == res);
    }
    {
        std::vector<int> nums = {1,2,5,2,3};
        int target = 3;
        std::vector<int> res = {3};
        assert(sol.targetIndices(nums, target) == res);
    }
    {
        std::vector<int> nums = {1,2,5,2,3};
        int target = 5;
        std::vector<int> res = {4};
        assert(sol.targetIndices(nums, target) == res);
    }
    return 0;
}