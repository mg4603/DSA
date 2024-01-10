#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    bool checkPossibility(std::vector<int>& nums) {
        int cnt = 0;
        for(int i = 0; i < nums.size() - 1; i++)
        {
            if(nums[i] > nums[i + 1])
            {
                cnt++;
                if(cnt > 1)
                {
                    return false;
                }

                if(i > 0 && nums[i - 1] > nums[i + 1])
                {
                    nums[i + 1] = nums[i];
                }
                else
                {
                    nums[i] = nums[i + 1];
                }
            }
        }
        return cnt <= 1;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {4,2,3};
        bool res = 1;
        assert(sol.checkPossibility(nums) == res);
    }
    {
        std::vector<int> nums = {4,2,1};
        bool res = 0;
        assert(sol.checkPossibility(nums) == res);
    }
    return 0;
}