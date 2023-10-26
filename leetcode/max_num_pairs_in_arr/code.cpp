#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    std::vector<int> numberOfPairs(std::vector<int>& nums) 
    {
        std::vector<int> freq(101, 0);
        for(int i = 0; i < nums.size(); i++)
        {
            freq[nums[i]]++;
        }
        std::vector<int> res(2, 0);
        for(int i = 0; i < 101; i++)
        {
            res[0] += freq[i] / 2;
            res[1] += freq[i] % 2;
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {1,3,2,1,3,2,2};
        std::vector<int> res = {3,1};
        assert(sol.numberOfPairs(nums) == res);
    }
    {
        std::vector<int> nums = {1,1};
        std::vector<int> res = {1,0};
        assert(sol.numberOfPairs(nums) == res);
    }
    {
        std::vector<int> nums = {0};
        std::vector<int> res = {0,1};
        assert(sol.numberOfPairs(nums) == res);
    }
    return 0;
}