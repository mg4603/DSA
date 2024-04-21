#include <iostream>
#include <assert.h>

#include <vector>
#include <unordered_map>

class Solution {
public:
    int maxNonOverlapping(std::vector<int>& nums, int target) {
        std::ios::sync_with_stdio(0);
        int left = -1;
        int right = 0;
        int prefix = 0;
        int res = 0;
        std::unordered_map<int, int> mp;
        mp[0] = -1;
        
        for(int i = 0; i < nums.size(); i++)
        {
            prefix += nums[i];
            if(mp.count(prefix - target))
            {
                right = mp[prefix - target];
                if(left <= right)
                {
                    res++;
                    left = i;
                }

            }
            mp[prefix] = i;
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {1,1,1,1,1};
        int target = 2;
        int res = 2;
        assert(sol.maxNonOverlapping(nums, target) == res);
    }
    return 0;
}