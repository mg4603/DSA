#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    std::vector<int> singleNumber(std::vector<int>& nums) 
    {
        int n = nums.size();

        int a_xor_b = 0;
        for(int i = 0; i < n; i++)
        {
            a_xor_b ^= nums[i];
        }

        int mask = 1;
        while(!(mask & a_xor_b))mask <<= 1;

        int first = 0;
        int second = 0;

        for(int i = 0; i < n; i++)
        {
            if(mask & nums[i])
            {
                first ^= nums[i];
            }
            else
            {
                second ^= nums[i];
            }
        }
        return {first, second};
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {1,2,1,3,2,5};
        std::vector<int> res = {3,5};
        assert(sol.singleNumber(nums) == res);
    }
    {
        std::vector<int> nums = {-1,0};
        std::vector<int> res = {-1,0};
        assert(sol.singleNumber(nums) == res);
    }
    {
        std::vector<int> nums = {0,1};
        std::vector<int> res = {1,0};
        assert(sol.singleNumber(nums) == res);
    }
    return 0;
}