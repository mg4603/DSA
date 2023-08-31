#include <iostream>
#include <assert.h>

#include <vector>
#include <algorithm>

class Solution {
public:
    int thirdMax(std::vector<int>& nums) {
        
        std::sort(nums.begin(), nums.end());
        nums.erase(std::unique(nums.begin(), nums.end()), nums.end());
        if(nums.size() <= 2)
        {
            return nums.back();
        }
        
        return nums[nums.size() - 3];
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {3,2,1};
        assert(sol.thirdMax(nums) == 1);
    }
    {
        std::vector<int> nums = {2,1};
        assert(sol.thirdMax(nums) == 2);
    }
    {
        std::vector<int> nums = {2,2,3,1};
        assert(sol.thirdMax(nums) == 1);
    }
    return 0;
}