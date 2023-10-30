#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    int sumOfSquares(std::vector<int>& nums) 
    {
        int res = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++)
        {
            if(n % (i + 1) == 0)
            {
                res += (nums[i] * nums[i]);
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {1,2,3,4};
        int res = 21;
        assert(sol.sumOfSquares(nums) == res);
    }
    {
        std::vector<int> nums = {2,7,1,19,18,3};
        int res = 63;
        assert(sol.sumOfSquares(nums) == res);
    }
    return 0;
}