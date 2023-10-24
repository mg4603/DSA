#include <iostream>
#include <assert.h>

#include <vector>
#include <unordered_map>

class Solution {
public:
    int countKDifference(std::vector<int>& nums, int k) {
        int res = 0;
        std::unordered_map<int, int> mp;
        for(int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]]++;
        }
        
        for(auto pair: mp)
        {
            int temp = 0;
            if(mp.count(pair.first + k))
            {
                temp = mp[pair.first + k];
            }
            res += temp * pair.second;
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {1,2,2,1};
        int k = 1;
        int res = 4;
        assert(sol.countKDifference(nums, k) == res);
    }
    {
        std::vector<int> nums = {1,3};
        int k = 3;
        int res = 0;
        assert(sol.countKDifference(nums, k) == res);
    }
    {
        std::vector<int> nums = {3,2,1,5,4};
        int k = 2;
        int res = 3;
        assert(sol.countKDifference(nums, k) == res);
    }
    return 0;
}