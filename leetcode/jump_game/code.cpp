#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    bool canJump(std::vector<int>& nums) 
    {
        int n = nums.size();
        int max_jump_pos = 0;
        int i = 0;
        int current_pos = 0;
        while(i < n - 1)
        {
            int jump = nums[i];
            int jump_pos = i + jump;
            max_jump_pos = std::max(max_jump_pos, jump_pos);

            if(i == current_pos)
            {
                if(current_pos == max_jump_pos)
                {
                    return false;
                }
                current_pos = max_jump_pos;
            }
            

            i++;
        }
        return true;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {2,3,1,1,4};
        bool res = true;
        assert(sol.canJump(nums) == res);
    }
    {
        std::vector<int> nums = {3,2,1,0,4};
        bool res = false;
        assert(sol.canJump(nums) == res);
    }
    return 0;
}