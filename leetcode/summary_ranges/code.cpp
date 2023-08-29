#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    std::vector<std::string> summaryRanges(std::vector<int>& nums) {
        std::vector<std::string> res;
        if(nums.size() == 0)
        {
            return res;
        }
        int start(0);
        for(int i(1); i < nums.size(); i++)
        {
            long long temp = static_cast<long long>(nums[i]) - static_cast<long long>(nums[i-1]);
            if(temp > 1)
            {
                if(start != i - 1)
                {
                res.push_back(std::to_string(nums[start])+"->" + std::to_string(nums[i-1]));
                }
                else if(start == i - 1)
                {
                    res.push_back(std::to_string(nums[start]));
                }
                start = i;
            }
        }

        if(start != nums.size() - 1)
        {
            res.push_back(std::to_string(nums[start]) + "->" + std::to_string(nums.back()) );
        }
        else
        {
            res.push_back(std::to_string(nums.back()));
        }

        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {0,1,2,4,5,7};
        std::vector<std::string> res = {"0->2","4->5","7"};
        assert(sol.summaryRanges(nums) == res);
    }
    {
        std::vector<int> nums = {0,2,3,4,6,8,9};
        std::vector<std::string> res = {"0","2->4","6","8->9"};
        assert(sol.summaryRanges(nums) == res);
    }
    return 0;
}