#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    std::vector<int> sortArrayByParity(std::vector<int>& nums) {
        std::vector<int> odds;
        std::vector<int> evens;
        for(int num: nums)
        {
            if(num % 2 == 0)
            {
                evens.push_back(num);
            }
            else
            {
                odds.push_back(num);
            }
        }
        for(int num: odds)
        {
            evens.push_back(num);
        }
        return evens;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {3,1,2,4};
        std::vector<int> res = {2,4,3,1};
        assert(sol.sortArrayByParity(nums) == res);
    }
    {
        std::vector<int> nums = {0};
        std::vector<int> res = {0};
        assert(sol.sortArrayByParity(nums) == res);
    }
    return 0;
}