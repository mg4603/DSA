#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    int smallestEqual(std::vector<int>& nums) 
    {
        std::ios_base::sync_with_stdio(0);
        int n = nums.size();
        for(int i = 0; i < n; i++)
        {
            if(i % 10 == nums[i])
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
        std::vector<int> nums = {0,1,2};
        int res = 0;
        assert(sol.smallestEqual(nums) == res);
    }
    {
        std::vector<int> nums = {4,3,2,1};
        int res = 2;
        assert(sol.smallestEqual(nums) == res);
    }
    {
        std::vector<int> nums = {1,2,3,4,5,6,7,8,9,0};
        int res = -1;
        assert(sol.smallestEqual(nums) == res);
    }
    return 0;
}