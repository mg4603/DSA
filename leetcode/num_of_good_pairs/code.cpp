#include <iostream>
#include <assert.h>

#include <vector>
#include <map>

class Solution {
public:
    int numIdenticalPairs(std::vector<int>& nums) {
        std::map<int, int> mp;
        for(int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]]++;
        }
        int res = 0;
        for(auto pair: mp)
        {
            res += (pair.second * (pair.second - 1)) / 2;
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {1,2,3,1,1,3};
        int res = 4;
        assert(sol.numIdenticalPairs(nums) == res);
    }
    {
        std::vector<int> nums = {1,1,1,1};
        int res = 6;
        assert(sol.numIdenticalPairs(nums) == res);
    }
    return 0;
}