#include <iostream>
#include <assert.h>

#include <vector>
#include <algorithm>

class Solution {
public:
    bool containsDuplicate(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        if(std::unique(nums.begin(), nums.end()) != nums.end())
        {
          return true;
        }
        return false;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {1, 2, 3, 1};
        assert(sol.containsDuplicate(nums) == true);
    }
    {
        std::vector<int> nums = {1, 2, 3, 4};
        assert(sol.containsDuplicate(nums) == false);
    }
    {
        std::vector<int> nums = {1,1,1,3,3,4,3,2,4,2};
        assert(sol.containsDuplicate(nums) == true);
    }
    return 0;
}