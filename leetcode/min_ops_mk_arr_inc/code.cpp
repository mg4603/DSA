#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    int minOperations(std::vector<int>& nums) {
        int res = 0;

        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i] > nums[i - 1])continue;
            int temp = nums[i - 1] - nums[i];
            temp++;
            nums[i] += temp;
            res += temp;
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {1,1,1};
        int res = 3;
        assert(sol.minOperations(nums) == res);
    }
    {
        std::vector<int> nums = {1,5,2,4,1};
        int res = 14;
        assert(sol.minOperations(nums) == res);
    }
    {
        std::vector<int> nums = {8};
        int res = 0;
        assert(sol.minOperations(nums) == res);
    }
    return 0;
}