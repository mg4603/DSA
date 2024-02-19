#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    int helper(std::vector<int>& nums, int goal) 
    {
        if(goal < 0)
        {
            return 0;
        }
        int i = 0;
        int j = 0;
        int res = 0;
        int n = nums.size();
        int sum = 0;
        while(j < n)
        {
            sum += nums[j];

            while(sum > goal)
            {
                sum -= nums[i];
                i++;
            }
            res += (j - i + 1);
            j++;
        }
        return res;  
    }
    
    int numSubarraysWithSum(std::vector<int>& nums, int goal) 
    {
        return helper(nums, goal) - helper(nums, goal - 1);
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int>nums = {1,0,1,0,1};
        int goal = 2;
        int res = 4;
        assert(sol.numSubarraysWithSum(nums, goal) == res);
    }
    return 0;
}