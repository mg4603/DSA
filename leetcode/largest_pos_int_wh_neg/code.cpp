#include <iostream>
#include <assert.h>

#include <vector>
#include <unordered_map>

class Solution {
public:
    int findMaxK(std::vector<int>& nums) {
        // first bool indicates presence of -ve and second of +ve
        std::unordered_map<int, std::pair<bool, bool>> mp;
        int res = -1;
        for(int i = 0; i < nums.size(); i++)
        {
            int temp = nums[i];
            
            if(temp < 0)
            {
                if(mp.count(-temp) == 0)
                {
                    mp[-temp] = std::make_pair(0, 0);
                }
                mp[-temp].first = 1;
                temp = -temp;
            }
            else
            {
                if(mp.count(temp) == 0)
                {
                    mp[temp] = std::make_pair(0, 0);
                }
                mp[temp].second = 1;
            }
            if(mp[temp].first && mp[temp].second && temp > res)
            {
                res = temp;
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {-1,2,-3,3};
        int res = 3;
        assert(sol.findMaxK(nums) == res);
    }
    {
        std::vector<int> nums = {-1,10,6,7,-7,1};
        int res = 7;
        assert(sol.findMaxK(nums) == res);
    }
    {
        std::vector<int> nums = {-10,8,6,7,-2,-3};
        int res = -1;
        assert(sol.findMaxK(nums) == res);
    }
    return 0;
}