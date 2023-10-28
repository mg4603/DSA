#include <iostream>
#include <assert.h>

#include <vector>
#include <limits>

class Solution {
public:
    int findClosestNumber(std::vector<int>& nums) 
    {
        int n = nums.size();
        if(n == 1)
        {
            return nums[0];
        }

        std::pair<int, int> res = std::make_pair(std::numeric_limits<int>::max(), 0);

        for(int i = 0; i < nums.size(); i++)
        {
            int temp = std::abs(nums[i]);
            if(res.first > temp)
            {
                res.first = temp;
                res.second = nums[i];
            }
            else if(res.first == temp)
            {
                if(res.second < nums[i])
                {
                    res.second = nums[i];
                }
            }
        }
        return res.second;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {-4,-2,1,4,8};
        int res = 1;
        assert(sol.findClosestNumber(nums) == res);
    }
    {
        std::vector<int> nums = {2,-1,1};
        int res = 1;
        assert(sol.findClosestNumber(nums) == res);
    }
    return 0;
}