#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    int countHillValley(std::vector<int>& nums) {
        std::vector<int> new_nums;
        for(int i = 0; i < nums.size(); i++)
        {
            if(i > 0 && nums[i] == nums[i - 1])continue;
            new_nums.push_back(nums[i]);
        }
        int res = 0;
        for(int i = 1; i < new_nums.size() - 1; i++)
        {
            if(new_nums[i] > new_nums[i - 1] && new_nums[i] > new_nums[i + 1])
            {
                res++;
            }
            if(new_nums[i] < new_nums[i - 1] && new_nums[i] < new_nums[i + 1])
            {
                res++;
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {2,4,1,1,6,5};
        int res = 3;
        assert(sol.countHillValley(nums) == res);
    }
    {
        std::vector<int> nums = {6,6,5,5,4,1};
        int res = 0;
        assert(sol.countHillValley(nums) == res);
    }
    return 0;
}