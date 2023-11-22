#include <iostream>
#include <assert.h>

#include <algorithm>
#include <vector>

class Solution {
public:
    std::string largestNumber(std::vector<int>& nums) 
    {
        std::sort(nums.begin(), nums.end(), [](auto a, auto b)
        {
            return std::to_string(a)+std::to_string(b) > 
                    std::to_string(b)+std::to_string(a);
        });
        std::string res;
        for(int i = 0; i < nums.size(); i++)
        {
            res += std::to_string(nums[i]);
        }
        if(res[0] == '0')
        {
            return "0";
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {10,2};
        std::string res = "210";
        assert(sol.largestNumber(nums) == res);
    }
    {
        std::vector<int> nums = {3,30,34,5,9};
        std::string res = "9534330";
        assert(sol.largestNumber(nums) == res);
    }
    return 0;
}