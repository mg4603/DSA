#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    int numSubarrayProductLessThanK(std::vector<int>& nums, 
                                    int k) {
        int prod = 1;
        int res = 0;
        int i = 0;
        int j = 0;
        int n = nums.size();

        for(; i < n; i++)
        {
            prod *= nums[i];

            while(j <= i && prod >= k)
            {
                prod /= nums[j];
                j++;
            }
            res += (i - j) + 1;
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {1,2,3};
        int k = 0;
        int res = 0;
        assert(sol.numSubarrayProductLessThanK(nums, k) == res);
    }
    return 0;
}