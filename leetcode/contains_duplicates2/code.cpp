#include <iostream>
#include <assert.h>

#include <map>
#include <vector>

class Solution {
public:
    bool containsNearbyDuplicate(std::vector<int>& nums, int k) {
        std::map<int, int> pos_mp;
        for(int i(0); i < nums.size(); i++)
        {
          if(pos_mp.count(nums[i]))
          {
            if(std::abs(pos_mp[nums[i]] - i) <= k)
            {
              return true;
            }
          }
          pos_mp[nums[i]] = i;
        }
        return false;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {1, 2, 3, 1};
        int k = 3;
        assert(sol.containsNearbyDuplicate(nums, k) == true);
    }
    {
        std::vector<int> nums = {1,0,1,1};
        int k = 1;
        assert(sol.containsNearbyDuplicate(nums, k) == true);
    }
    {
        std::vector<int> nums = {1,2,3,1,2,3};
        int k = 2;
        assert(sol.containsNearbyDuplicate(nums, k) == false);
    }
    return 0;
}