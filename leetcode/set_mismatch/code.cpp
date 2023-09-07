#include <iostream>
#include <assert.h>

#include <vector>
#include <map>

class Solution {
public:
    std::vector<int> findErrorNums(std::vector<int>& nums) {
        std::map<int, int> mp;
        for(int num: nums)
        {
            mp[num]++;
        }
        std::vector<int> res;
        int repeated;
        int missing;
        for(int i(1); i <= nums.size(); i++)
        {
            if(mp.count(i) == 0)
            {
                missing = i;
            }
            else if(mp[i] > 1)
            {
                repeated = i;
            }
        }
        res.push_back(repeated);
        res.push_back(missing);
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {1,2,2,4};
        std::vector<int> res = {2,3};
        assert(sol.findErrorNums(nums) == res);
    }
    {
        std::vector<int> nums = {1,1};
        std::vector<int> res = {1,2};
        assert(sol.findErrorNums(nums) == res);
    }
    return 0;
}