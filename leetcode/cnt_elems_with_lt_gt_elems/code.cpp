#include <iostream>
#include <assert.h>

#include <vector>
#include <map>

class Solution {
public:
    int countElements(std::vector<int>& nums) 
    {
        std::ios_base::sync_with_stdio(0);
        int res = 0;
        std::map<int, int> mp;
        
        for(int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]]++;
        }
        int i = 0;
        for(auto it: mp)
        {
            i++;
            if(i == 1 || i == mp.size())continue;
            res += it.second;
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {11,7,2,15};
        int res = 2;
        assert(sol.countElements(nums) == res);
    }
    {
        std::vector<int> nums = {-3,3,3,90};
        int res = 2;
        assert(sol.countElements(nums) == res);
    }
    return 0;
}