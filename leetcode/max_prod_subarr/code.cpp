#include <iostream>
#include <assert.h>

#include <vector>
#include <limits>

class Solution {
public:
    int maxProduct(std::vector<int>& nums) 
    {
        int res = std::numeric_limits<int>::min();

        int n = nums.size();
        int prod = 1;
        for(int i = 0; i < n; i++)
        {
            prod *= nums[i];
            res = std::max(prod, res);
            if(prod == 0)
            {
                prod = 1;
            }
        }
        prod = 1;
        for(int i = n - 1; i >= 0; i--)
        {
            prod *= nums[i];
            res  = std::max(prod, res);
            if(prod == 0)
            {
                prod = 1;
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {2,3,-2,4};
        int res = 6;
        assert(sol.maxProduct(nums) == res);
    }
    {
        std::vector<int> nums = {-2,0,-1};
        int res = 0;
        assert(sol.maxProduct(nums) == res);
    }
    return 0;
}