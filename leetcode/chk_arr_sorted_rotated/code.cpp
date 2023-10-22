#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    bool check(std::vector<int>& nums) {
        int decreasing = 0;
        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i] < nums[i - 1])
            {
                decreasing++;
            }
        }
        return (decreasing == 0) || (decreasing == 1 && nums[0] >= nums.back());
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {3,4,5,1,2};
        bool res = true;
        assert(sol.check(nums) == res);
    }
    {
        std::vector<int> nums = {2,1,3,4};
        bool res = false;
        assert(sol.check(nums) == res);
    }
    {
        std::vector<int> nums = {1,2,3};
        bool res = true;
        assert(sol.check(nums) == res);
    }
    return 0;
}