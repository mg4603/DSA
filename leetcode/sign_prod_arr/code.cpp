#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    int arraySign(std::vector<int>& nums) {
        int count(0);
        for(int num: nums)
        {
            if(num == 0)
            {
                return 0;
            }
            else if(num < 0)
            {
                count++;
            }
        }
        return count % 2 == 1? -1: 1;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {-1,-2,-3,-4,3,2,1};
        assert(sol.arraySign(nums) == 1);
    }
    {
        std::vector<int> nums = {1,5,0,2,-3};
        assert(sol.arraySign(nums) == 0);
    }
    {
        std::vector<int> nums = {-1,1,-1,1,-1};
        assert(sol.arraySign(nums) == -1);
    }
    return 0;
}