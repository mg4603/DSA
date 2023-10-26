#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    int minMaxGame(std::vector<int>& nums) 
    {
        int n = nums.size();
        while(n > 1)
        {
            std::vector<int> new_nums;
            int cnt = 0;
            for(int i = 0; i < n; i += 2)
            {
                if(cnt % 2 == 0)
                {
                    new_nums.push_back(std::min(nums[i], nums[i + 1]));
                }
                else
                {
                    new_nums.push_back(std::max(nums[i], nums[i + 1]));
                }
                cnt++;
            }
            nums = new_nums;
            n = nums.size();
        }
        return nums.back();
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {1,3,5,2,4,8,2,2};
        int res = 1;
        assert(sol.minMaxGame(nums) == res);
    }
    {
        std::vector<int> nums = {3};
        int res = 3;
        assert(sol.minMaxGame(nums) == res);
    }
    return 0;
}