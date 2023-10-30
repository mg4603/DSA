#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    int alternatingSubarray(std::vector<int>& nums) 
    {
        int n = nums.size();    

        int diff = 1;
        int res = -1;
        int count = 1;

        for(int i = 1; i < n; i++)
        {
            if(nums[i] - nums[i - 1] == diff)
            {
                while(i < n)
                {
                    if(nums[i] - nums[i - 1] != diff)break;
                    diff *= -1;
                    count++;
                    i++;
                }
                if(count > 1 && count > res)
                {
                    res = count;
                }
                i--;
                count = 1;
                diff = 1;
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {2,3,4,3,4};
        int res = 4;
        assert(sol.alternatingSubarray(nums) == res);
    }
    {
        std::vector<int> nums = {4,5,6};
        int res = 2;
        assert(sol.alternatingSubarray(nums) == res);
    }
    return 0;
}