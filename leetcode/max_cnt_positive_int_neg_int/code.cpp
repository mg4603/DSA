#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    int maximumCount(std::vector<int>& nums) 
    {
        std::ios_base::sync_with_stdio(0);
        int positives = 0;
        int negatives = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] < 0)
            {
                negatives++;
            }
            else if(nums[i] > 0)
            {
                positives++;
            }
        }
        return std::max(negatives, positives);
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {-2,-1,-1,1,2,3};
        int res = 3;
        assert(sol.maximumCount(nums) == res);
    }
    {
        std::vector<int> nums = {-3,-2,-1,0,0,1,2};
        int res = 3;
        assert(sol.maximumCount(nums) == res);
    }
    {
        std::vector<int> nums = {5,20,66,1314};
        int res = 4;
        assert(sol.maximumCount(nums) == res);
    }
    return 0;
}