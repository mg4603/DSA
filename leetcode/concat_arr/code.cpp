#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    std::vector<int> getConcatenation(std::vector<int>& nums) 
    {
        int n = nums.size();
        for(int i = 0; i < n; i++)
        {
            nums.push_back(nums[i]);
        }
        return nums;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {1,2,1};
        std::vector<int> res = {1,2,1,1,2,1};
        assert(sol.getConcatenation(nums) == res);
    }
    {
        std::vector<int> nums = {1,3,2,1};
        std::vector<int> res = {1,3,2,1,1,3,2,1};
        assert(sol.getConcatenation(nums) == res);
    }
    return 0;
}