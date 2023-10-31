#include <iostream>
#include <assert.h>

#include <vector>
#include <algorithm>

class Solution {
public:
    int countPairs(std::vector<int>& nums, int target) 
    {
        int res = 0;
        
        std::sort(nums.begin(), nums.end());
        int n = nums.size();

        for(int i = 0; i < n; i++)
        {
            for(int j = i + 1; j < n; j++)
            {
                if(nums[i] + nums[j] >= target)break;
                res++;
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {-1,1,2,3,1};
        int target = 2;
        int res = 3;
        assert(sol.countPairs(nums, target) == res);
    }
    {
        std::vector<int> nums = {-6,2,5,-2,-7,-1,3};
        int target = -2;
        int res = 10;
        assert(sol.countPairs(nums, target) == res);
    }
    return 0;
}