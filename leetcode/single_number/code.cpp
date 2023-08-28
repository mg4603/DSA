#include <iostream>
#include <assert.h>

#include <vector>
#include <algorithm>

class Solution {
public:
    int singleNumber(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        for(int i(0); i < nums.size(); i += 2)
        {
            if(i + 1 == nums.size())
            {
                return nums[i];
            }
            else if(nums[i + 1] != nums[i])
            {
                return nums[i];
            }
        }
        return -1;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> vec = {2,2,1};
        assert(sol.singleNumber(vec) == 1);
    }
    {
        std::vector<int> vec = {4,1,2,1,2};
        assert(sol.singleNumber(vec) == 4);
    }
    {
        std::vector<int> vec = {1};
        assert(sol.singleNumber(vec) == 1);
    }
    return 0;
}