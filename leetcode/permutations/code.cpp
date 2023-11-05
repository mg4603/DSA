#include <iostream>
#include <assert.h>

#include <vector>
#include <algorithm>

class Solution {
    void helper(std::vector<std::vector<int>> &res, 
                std::vector<int> temp, std::vector<int> nums)
    {
        if(temp.size() == nums.size())
        {
            res.push_back(temp);
            return;
        }

        for(int i = 0; i < nums.size(); i++)
        {
            if(std::find(temp.begin(), 
                temp.end(), nums[i]) != temp.end())continue;
            temp.push_back(nums[i]);
            helper(res, temp, nums);
            temp.pop_back();
        }
        
    }   
public:
    std::vector<std::vector<int>> permute(std::vector<int>& nums) 
    {
        std::vector<std::vector<int>> res;
        helper(res, {}, nums);
        return res;    
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {1,2,3};
        std::vector<std::vector<int>> res = {{1,2,3},{1,3,2},{2,1,3},
                                             {2,3,1},{3,1,2},{3,2,1}};
        assert(sol.permute(nums) == res);
    }
    {
        std::vector<int> nums = {0,1};
        std::vector<std::vector<int>> res = {{0,1},{1,0}};
        assert(sol.permute(nums) == res);
    }
    {
        std::vector<int> nums = {1};
        std::vector<std::vector<int>> res = {{1}};
        assert(sol.permute(nums) == res);
    }
    return 0;
}