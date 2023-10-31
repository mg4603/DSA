#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    std::vector<int> findIndices(std::vector<int>& nums, 
                                 int indexDifference, 
                                 int valueDifference) 
    {
        int n = nums.size();

        for(int i = 0; i < n - indexDifference; i++)
        {
            for(int j = indexDifference; i + j < n; j++)
            {
                if(std::abs(nums[i] - nums[i + j]) >= valueDifference)
                {
                    return {i, j + i};
                }
            }
        }
        return {-1, -1};
    }   
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {5,1,4,1};
        int indexDifference = 2;
        int valueDifference = 4;
        std::vector<int> res = {0,3};
        assert(sol.findIndices(nums, indexDifference, valueDifference) == res);
    }
    {
        std::vector<int> nums = {2,1};
        int indexDifference = 0;
        int valueDifference = 0;
        std::vector<int> res = {0,0};
        assert(sol.findIndices(nums, indexDifference, valueDifference) == res);
    }
    {
        std::vector<int> nums = {1,2,3};
        int indexDifference = 2;
        int valueDifference = 4;
        std::vector<int> res = {-1,-1};
        assert(sol.findIndices(nums, indexDifference, valueDifference) == res);
    }
    return 0;
}