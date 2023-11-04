#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    int jump(std::vector<int>& nums) 
    {
        int res = 0;
        int n = nums.size();
        int max_jump_pos = 0;
        int end = 0;

        for(int i = 0; i < n - 1; i++)
        {
            int jump_dist = nums[i];
            int jump_pos = jump_dist + i;
            max_jump_pos = std::max(jump_pos, max_jump_pos );

            if(i == end)
            {
                res++;
                end = max_jump_pos; 
            }    
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {2,3,1,1,4};
        int res = 2;
        assert(sol.jump(nums) == res);
    }
    {
        std::vector<int> nums = {2,3,0,1,4};
        int res = 2;
        assert(sol.jump(nums) == res);
    }
    return 0;
}