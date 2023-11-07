#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
    void helper(std::vector<std::vector<int>> &res, 
                std::vector<int> &nums, int size, 
                int start, std::vector<int> temp)
    {
        if(size > nums.size())
        {
            return;
        }
        if(temp.size() == size)
        {
            res.push_back(temp);
        }
        
        for(int i = start; i < nums.size(); i++)
        {
            temp.push_back(nums[i]);
            helper(res, nums, size + 1, i + 1, temp);
            temp.pop_back();
        }
    }
public:
    std::vector<std::vector<int>> subsets(std::vector<int>& nums) 
    {
        std::vector<std::vector<int>> res;
        helper(res, nums, 0, 0, {});
        return res;    
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {1,2,3};
        std::vector<std::vector<int>> res = {{},{1},{1,2},{1,2,3},{1,3},{2},{2,3},{3}};
        assert(sol.subsets(nums) == res);
    }
    {
        std::vector<int> nums = {0};
        std::vector<std::vector<int>> res = {{},{0}};
        assert(sol.subsets(nums) == res);
    }
    return 0;
}