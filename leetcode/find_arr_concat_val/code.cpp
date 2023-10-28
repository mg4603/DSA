#include <iostream>
#include <assert.h>

#include <vector>
#include <cmath>

class Solution {
public:
    long long findTheArrayConcVal(std::vector<int>& nums) 
    {
        long long res = 0;
        int i = 0;
        int j = nums.size() - 1;
        while(i < j)
        {
            int exp = std::log10(nums[j]) + 1;
            res += nums[j--];
            res += (nums[i++] * std::pow(10, exp));
        }
        if(i == j)
        {
            res += nums[i];
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {7,52,2,4};
        int res = 596;
        assert(sol.findTheArrayConcVal(nums) == res);
    }
    {
        std::vector<int> nums = {5,14,13,8,12};
        int res = 673;
        assert(sol.findTheArrayConcVal(nums) == res);
    }
    return 0;
}