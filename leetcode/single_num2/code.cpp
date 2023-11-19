#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    int singleNumber(std::vector<int> &nums) 
    {
        int res = 0;
        int n = nums.size();

        for(int i = 0; i <= 31; i++)
        {
            int sum = 0;
            for(int j = 0; j < n; j++)
            {
                sum += ((nums[j] >> i) & 1);
            }
            sum %= 3;
            res |= sum << i;
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {2,2,3,2};
        int res = 3;
        assert(sol.singleNumber(nums) == res);
    }
    {
        std::vector<int> nums = {0,1,0,1,0,1,99};
        int res = 99;
        assert(sol.singleNumber(nums) == res);
    }
    return 0;
}