#include <iostream>
#include <assert.h>

#include <vector>
#include <unordered_map>

class Solution {
public:
    int findPairs(std::vector<int>& nums, int k) 
    {
        int res = 0;
        std::unordered_map<int, int> mp;
        for(int num: nums)
        {
            mp[num]++;
        }

        for(std::pair<int, int> it: mp)
        {
            if((k == 0 && mp[it.first] > 1) || 
               (k > 0 && mp.count(k + it.first)))
            {
                res++;
            }
        }

        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {3,1,4,1,5};
        int k = 2;
        int res = 2;
        assert(sol.findPairs(nums, k) == res);
    }
    {
        std::vector<int> nums = {1,2,3,4,5};
        int k = 1;
        int res = 4;
        assert(sol.findPairs(nums, k) == res);
    }
    {
        std::vector<int> nums = {1,3,1,5,4};
        int k = 0;
        int res = 1;
        assert(sol.findPairs(nums, k) == res);
    }
    return 0;
}