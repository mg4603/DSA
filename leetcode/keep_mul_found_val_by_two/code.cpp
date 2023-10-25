#include <iostream>
#include <assert.h>

#include <vector>
#include <algorithm>

class Solution {
public:
    int findFinalValue(std::vector<int>& nums, int original) 
    {
        std::ios_base::sync_with_stdio(0);
        std::sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == original)
            {
                original *= 2;
            }
        }
        return original;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {5,3,6,1,12};
        int original = 3;
        int res = 24;
        assert(sol.findFinalValue(nums, original) == res);
    }
    {
        std::vector<int> nums = {2,7,9};
        int original = 4;
        int res = 4;
        assert(sol.findFinalValue(nums, original) == res);
    }
    return 0;
}