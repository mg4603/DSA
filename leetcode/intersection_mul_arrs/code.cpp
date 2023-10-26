#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    std::vector<int> intersection(std::vector<std::vector<int>>& nums) 
    {
        int n = nums.size();
        std::vector<int> freq(1001, 0);
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < nums[i].size(); j++)
            {
                freq[nums[i][j]]++;
            }
        }
        std::vector<int> res;
        for(int i = 1; i < 1001; i++)
        {
            if(freq[i] == 0)continue;
            if(freq[i] == n)
            {
                res.push_back(i);
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<std::vector<int>> nums = {{3,1,2,4,5},{1,2,3,4},{3,4,5,6}};
        std::vector<int> res = {3,4};
        assert(sol.intersection(nums) == res);
    }
    {
        std::vector<std::vector<int>> nums = {{1,2,3},{4,5,6}};
        std::vector<int> res = {};
        assert(sol.intersection(nums) == res);
    }
    return 0;
}