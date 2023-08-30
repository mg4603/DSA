#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    void moveZeroes(std::vector<int>& nums) {
        int i(0);
        int j(0);
        while(i < nums.size())
        {
            if(nums[i] != 0)
            {
                nums[j++] = nums[i];
            }
            i++;
        }
        while(j < nums.size())
        {
            nums[j++] = 0;
        }
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {0,1,0,3,12};
        std::vector<int> res = {1,3,12,0,0};
        sol.moveZeroes(nums);
        assert(nums == res);
    }
    {
        std::vector<int> nums = {0};
        std::vector<int> res = {0};
        sol.moveZeroes(nums);
        assert(nums == res);
    }
    return 0;
}