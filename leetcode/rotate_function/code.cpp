#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    int maxRotateFunction(std::vector<int>& nums) 
    {
        int n = nums.size();
        int sum = 0;
        int f_sum = 0;
        
        for(int i = 0; i < n; i++)
        {
            sum += nums[i];
            f_sum += (i * nums[i]);

        }

        int res = f_sum;
        for(int i = n - 1; i >= 0; i--)
        {
            f_sum += (sum - (nums[i] * n));
            if(f_sum > res)
            {
                res = f_sum;
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {4,3,2,6};
        int res = 26;
        assert(sol.maxRotateFunction(nums) == res);
    }
    {
        std::vector<int> nums = {100};
        int res = 0;
        assert(sol.maxRotateFunction(nums) == res);
    }
    return 0;
}