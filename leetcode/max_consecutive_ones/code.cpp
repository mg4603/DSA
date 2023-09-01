#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    int findMaxConsecutiveOnes(std::vector<int>& nums) {
        int res(0);
        int count(0);
        for(int i(0); i < nums.size(); i++)
        {
            if(nums[i] != 1)
            {
                count = 0;
            }
            else
            {
                count++;
            }
            if(count > res)
            {
                res = count;
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {1,1,0,1,1,1};
        assert(sol.findMaxConsecutiveOnes(nums) == 3);
    }
    {
        std::vector<int> nums = {1,0,1,1,0,1};
        assert(sol.findMaxConsecutiveOnes(nums) == 2);
    }
    return 0;
}