#include <iostream>
#include <assert.h>

#include <vector>
#include <algorithm>

class Solution {
public:
    int longestConsecutive(std::vector<int>& nums) 
    {
        int n = nums.size();
        if(n == 0)
        {
            return 0;
        }

        std::sort(nums.begin(), nums.end());
        nums.erase(std::unique(nums.begin(), nums.end()), nums.end());
        int len = 1;
        int res = 0;

        for(int i = 1; i < n; i++)
        {
            if(nums[i] - nums[i - 1] == 1)
            {
                len++;
            }
            else
            {
                if(len > res)
                {
                    res = len;
                }
                len = 1;
            }
        }
        if(len > res)
        {
            res = len;
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {100,4,200,1,3,2};
        int res = 4;
        assert(sol.longestConsecutive(nums) == res);
    }
    {
        std::vector<int> nums = {0,3,7,2,5,8,4,6,0,1};
        int res = 9;
        assert(sol.longestConsecutive(nums) == res);
    }
    return 0;
}