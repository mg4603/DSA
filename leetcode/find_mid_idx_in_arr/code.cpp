#include <iostream>
#include <assert.h>

#include <vector>
#include <numeric>

class Solution {
public:
    int findMiddleIndex(std::vector<int>& nums) 
    {
        int rightSum = std::accumulate(nums.begin(), nums.end(), 0);
        int leftSum = 0;

        for(int i = 0; i < nums.size(); i++)
        {
            rightSum -= nums[i];
            if(rightSum == leftSum)
            {
                return i;
            }
            leftSum += nums[i];
        }
        return -1;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {2,3,-1,8,4};
        int res = 3;
        assert(sol.findMiddleIndex(nums) == res);
    }
    {
        std::vector<int> nums = {1,-1,4};
        int res = 2;
        assert(sol.findMiddleIndex(nums) == res);
    }
    {
        std::vector<int> nums = {2,5};
        int res = -1;
        assert(sol.findMiddleIndex(nums) == res);
    }
    return 0;
}