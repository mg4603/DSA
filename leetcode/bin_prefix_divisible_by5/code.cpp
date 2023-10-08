#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    std::vector<bool> prefixesDivBy5(std::vector<int>& nums) {
        std::vector<bool> div_by_5(nums.size(), 0);

        int num = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            num = (num * 2 + nums[i]) % 5;
            if(num == 0)
            {
                div_by_5[i] = 1;
            }
        }
        return div_by_5;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {0,1,1};
        std::vector<bool> res = {true,false,false};
        assert(sol.prefixesDivBy5(nums) == res);
    }
    {
        std::vector<int> nums = {1,1,1};
        std::vector<bool> res = {false,false,false};
        assert(sol.prefixesDivBy5(nums) == res);
    }
    return 0;
}