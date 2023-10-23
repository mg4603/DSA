#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    std::vector<int> buildArray(std::vector<int>& nums) 
    {
        int n = nums.size();
        std::vector<int> res(n, 0);
        for(int i = 0; i < nums.size(); i++)
        {
            res[i] = nums[nums[i]];
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {0,2,1,5,3,4};
        std::vector<int> res = {0,1,2,4,5,3};
        assert(sol.buildArray(nums) == res);
    }
    {
        std::vector<int> nums = {5,0,1,2,3,4};
        std::vector<int> res = {4,5,0,1,2,3};
        assert(sol.buildArray(nums) == res);
    }
    return 0;
}