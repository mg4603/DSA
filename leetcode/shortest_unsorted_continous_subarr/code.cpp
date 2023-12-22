#include <iostream>
#include <assert.h>

#include <vector>
#include <algorithm>

class Solution {
public:
    int findUnsortedSubarray(std::vector<int>& nums) 
    {
        std::vector<int> sorted_nums = nums;
        std::sort(sorted_nums.begin(), sorted_nums.end());
        int start = -1;
        int end = -1;
        int n = nums.size();

        for(int i = 0; i < n; i++)
        {
            if(nums[i] != sorted_nums[i])
            {
                start = i;
                break;
            }
        }

        for(int i = n - 1; i >= 0; i--)
        {
            if(nums[i] != sorted_nums[i])
            {
                end = i;
                break;
            }
        }

        if(end == start)
        {
            return 0;
        }
        return end - start + 1;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {2,6,4,8,10,9,15};
        int res = 5;
        assert(sol.findUnsortedSubarray(nums) == res);
    }
    {
        std::vector<int> nums = {1,2,3,4};
        int res = 0;
        assert(sol.findUnsortedSubarray(nums) == res);
    }
    {
        std::vector<int> nums = {1};
        int res = 0;
        assert(sol.findUnsortedSubarray(nums) == res);
    }
    return 0;
}