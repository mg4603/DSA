#include <iostream>
#include <assert.h>

#include <vector>
#include <algorithm>

class Solution {
    void helper(std::vector<std::vector<int>> &res, 
                std::vector<int> & nums, 
                std::vector<int> &freq, 
                std::vector<int> temp)
    {
        if(temp.size() == nums.size())
        {
            res.push_back(temp);
            return;
        }
        for(int i = 0; i < nums.size(); i++)
        {
            if(i - 1 >= 0 && nums[i - 1] == nums[i])continue;
            if(freq[nums[i] + 10] == 0)continue;
            temp.push_back(nums[i]);
            freq[nums[i] + 10]--;
            helper(res, nums, freq, temp);
            freq[nums[i] + 10]++;
            temp.pop_back();
        }
    }
public:
    std::vector<std::vector<int>> permuteUnique(std::vector<int>& nums) 
    {
        std::vector<int> freq(21, 0);
        for(int i = 0; i < nums.size(); i++)
        {
            freq[nums[i] + 10]++;
        }
        std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> res;
        helper(res, nums, freq, {});
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {1,1,2};
        std::vector<std::vector<int>> res = {{1,1,2},{1,2,1},{2,1,1}};
        assert(sol.permuteUnique(nums) == res);
    }
    {
        std::vector<int> nums = {1,2,3};
        std::vector<std::vector<int>> res = {{1,2,3},{1,3,2},{2,1,3},
                                             {2,3,1},{3,1,2},{3,2,1}};
        assert(sol.permuteUnique(nums) == res);
    }
    return 0;
}