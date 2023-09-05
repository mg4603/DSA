#include <iostream>
#include <assert.h>

#include <vector>
#include <algorithm>

class Solution {
public:
    int arrayPairSum(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int sum(0);
        for(int i(0); i < nums.size(); i+=2)
        {
            sum += nums[i];
        }
        return sum;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {1,4,3,2};
        assert(sol.arrayPairSum(nums) == 4);
    }
    {
        std::vector<int> nums = {6,2,6,5,1,2};
        assert(sol.arrayPairSum(nums) == 9);
    }
    return 0;
}