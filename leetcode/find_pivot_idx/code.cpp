#include <iostream>
#include <assert.h>

#include <numeric>
#include <vector>

class Solution {
public:
    int pivotIndex(std::vector<int>& nums) {
        int rightSum(std::accumulate(nums.begin(), nums.end(), 0));
        int leftSum(0);

        for(int i(0); i < nums.size(); i++)
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
        std::vector<int> nums = {1,7,3,6,5,6};
        int res = 3;
        assert(sol.pivotIndex(nums) == res);
    }
    {
        std::vector<int> nums = {1,2,3};
        int res = -1;
        assert(sol.pivotIndex(nums) == res);
    }
    {
        std::vector<int> nums = {2,1,-1};
        int res = 0;
        assert(sol.pivotIndex(nums) == res);
    }
    return 0;
}