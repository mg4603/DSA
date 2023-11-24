#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
    int solve(std::vector<int> &nums, int n)
    {
        int prev2 = 0;
        int prev1 = nums[0];
        int curr = 0;

        for(int i = 1; i < n; i++)
        {
            curr = std::max(prev2 + nums[i], prev1);

            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
public:
    int rob(std::vector<int>& nums) 
    {
        int n = nums.size();
        if(n == 1)
        {
            return nums[0];
        }
        std::vector<int> first;
        std::vector<int> last;


        for(int i = 0; i < n; i++)
        {
            if(i != 0)
            {
                last.push_back(nums[i]);
            }
            if(i != n - 1)
            {
                first.push_back(nums[i]);
            }
        }
        return std::max(solve(first, n - 1), solve(last, n - 1));
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {2,3,2};
        int res = 3;
        assert(sol.rob(nums) == res);
    }
    {
        std::vector<int> nums = {1,2,3,1};
        int res = 4;
        assert(sol.rob(nums) == res);
    }
    {
        std::vector<int> nums = {1,2,3};
        int res = 3;
        assert(sol.rob(nums) == res);
    }
    return 0;
}