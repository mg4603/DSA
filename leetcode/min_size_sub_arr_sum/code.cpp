#include <iostream>
#include <assert.h>

#include <vector>
#include <limits>

class Solution {
public:
    int minSubArrayLen(int target, std::vector<int>& nums) 
    {
        int res = std::numeric_limits<int>::max();

        int flag1 = false;
        int flag2 = false;
        int i = 0;
        int j = 0;
        int n = nums.size();
        int rolling_sum = 0;


        while(!flag1 || !flag2)
        {
            flag1 = true;
            flag2 = true;

            while(i < n && rolling_sum < target)
            {
                rolling_sum += nums[i++];
                flag1 = false;
            }

            while(rolling_sum >= target)
            {
                if(i - j < res)
                {
                    res = i - j;
                }
                rolling_sum -= nums[j++];
            }

        }
        return res == std::numeric_limits<int>::max()? 0: res;
    }
};

int main()
{
    Solution sol;
    {
        int target = 7;
        std::vector<int> nums = {2,3,1,2,4,3};
        int res = 2;
        assert(sol.minSubArrayLen(target, nums) == res);
    }
    {
        int target = 4;
        std::vector<int> nums = {1,4,4};
        int res = 1;
        assert(sol.minSubArrayLen(target, nums) == res);
    }
    {
        int target = 11;
        std::vector<int> nums = {1,1,1,1,1,1,1,1};
        int res = 0;
        assert(sol.minSubArrayLen(target, nums) == res);
    }
    return 0;
}