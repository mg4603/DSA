#include <iostream>
#include <assert.h>

#include <vector>
#include <numeric>

class Solution {
public:
    int findNonMinOrMax(std::vector<int>& nums) 
    {
        std::vector<bool> freq(101, 0);
        int least_num = 101;
        for(int i = 0; i < nums.size(); i++)
        {
            if(least_num > nums[i])
            {
                least_num = nums[i];
            }
            freq[nums[i]] = 1;
        }
        
        if(std::accumulate(freq.begin(), freq.end(), 0) < 3)
        {
            return -1;
        }
        
        for(int i = least_num + 1; i < 101; i++)
        {
            if(freq[i] > 0)
            {
                return i;
            }
        }
        return -1;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {3,2,1,4};
        int res = 2;
        assert(sol.findNonMinOrMax(nums) == res);
    }
    {
        std::vector<int> nums = {1,2};
        int res = -1;
        assert(sol.findNonMinOrMax(nums) == res);
    }
    {
        std::vector<int> nums = {2,1,3};
        int res = 2;
        assert(sol.findNonMinOrMax(nums) == res);
    }
    return 0;
}