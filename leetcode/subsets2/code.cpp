#include <iostream>
#include <assert.h>

#include <vector>
#include <set>
#include <algorithm>

class Solution {
    void helper(std::vector<int> nums, 
                std::set<std::vector<int>> &res, 
                int start, int size, std::vector<int> temp)
    {
        if(size > nums.size())
        {
            return;
        }
        if(temp.size() == size)
        {
            std::sort(temp.begin(), temp.end());
            res.insert(temp);
        }
        for(int i = start; i < nums.size(); i++)
        {
            temp.push_back(nums[i]);
            helper(nums, res, i + 1, size + 1, temp);
            temp.pop_back();
        }
    }
public:
    std::vector<std::vector<int>> subsetsWithDup(std::vector<int>& nums) 
    {
        std::set<std::vector<int>> res;
        helper(nums, res, 0, 0, {});
        return std::vector<std::vector<int>>(res.begin(), res.end());    
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {1,2,2};
        std::vector<std::vector<int>> res = {{},{1},{1,2},{1,2,2},{2},{2,2}};
        assert(sol.subsetsWithDup(nums) == res);
    }
    {
        std::vector<int> nums = {0};
        std::vector<std::vector<int>> res = {{},{0}};
        assert(sol.subsetsWithDup(nums) == res);
    }
    return 0;
}