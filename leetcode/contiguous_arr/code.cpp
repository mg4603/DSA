#include <iostream>
#include <assert.h>

#include <vector>
#include <unordered_map>

class Solution {
public:
    int findMaxLength(std::vector<int>& nums) 
    {
        int n = nums.size();
        std::unordered_map<int, int> mp;
        int res = 0;
        int running_sum = 0;
        mp[0] = -1;

        for(int i = 0; i < n; i++)
        {
            if(nums[i])
            {
                running_sum++;
            }
            else
            {
                running_sum--;
            }

            if(mp.count(running_sum) == 0)
            {
                mp[running_sum] = i;
            }
            int temp = i - mp[running_sum];
            if(temp > res)
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
        std::vector<int> nums = {0,1};
        int res = 2;
        assert(sol.findMaxLength(nums) == res);
    }
    {
        std::vector<int> nums = {0,1,0};
        int res = 2;
        assert(sol.findMaxLength(nums) == res);
    }
    return 0;
}