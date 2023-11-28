#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    std::vector<int> productExceptSelf(std::vector<int>& nums) 
    {
        int n = nums.size();
        std::vector<int> left(n, 1);
        std::vector<int> right(n, 1);

        for(int i = 1; i < n; i++)
        {
            left[i] = left[i - 1] * nums[i - 1];
        }

        for(int i = n - 2; i >= 0; i--)
        {
            right[i] = right[i + 1] * nums[i + 1];
        }

        for(int i = 0; i < n; i++)
        {
            nums[i] = left[i] * right[i];
        }
        return nums;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {1,2,3,4};
        std::vector<int> res = {24,12,8,6};
        assert(sol.productExceptSelf(nums) == res);
    }
    {
        std::vector<int> nums = {-1,1,0,-3,3};
        std::vector<int> res = {0,0,9,0,0};
        assert(sol.productExceptSelf(nums) == res);
    }
    return 0;
}