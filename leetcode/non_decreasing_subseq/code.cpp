#include <iostream>
#include <assert.h>

#include <vector>
#include <limits>
#include <set>

class Solution {
    void helper(std::set<std::vector<int>> &res, 
                std::vector<int> &nums, 
                std::vector<int> temp, 
                int start, int prev)
    {
        if(temp.size() >= 2 && res.find(temp) == res.end())
        {
            res.insert(temp);
        }

        for(int i = start; i < nums.size(); i++)
        {
            if(nums[i] >= prev)
            {
                temp.push_back(nums[i]);
                helper(res, nums, temp, i + 1, nums[i]);
                temp.pop_back();
            }
        }
    }
public:
    std::vector<std::vector<int>> findSubsequences(
                                    std::vector<int>& nums) 
    {
        std::set<std::vector<int>> res;
        helper(res, nums, {}, 0, std::numeric_limits<int>::min());
        return std::vector<std::vector<int>>(res.begin(), res.end());
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {4,6,7,7};
        std::vector<std::vector<int>> res = {{4,6},{4,6,7},{4,6,7,7},
                                             {4,7},{4,7,7},{6,7},
                                             {6,7,7},{7,7}};
        assert(sol.findSubsequences(nums) == res);
    }
    {
        std::vector<int> nums = {4,4,3,2,1};
        std::vector<std::vector<int>> res = {{4,4}};
        assert(sol.findSubsequences(nums) == res);
    }
    return 0;
}