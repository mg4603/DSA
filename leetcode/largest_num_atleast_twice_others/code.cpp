#include <iostream>
#include <assert.h>

#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    int dominantIndex(std::vector<int>& nums) {
        std::unordered_map<int, int> pos;
        int i(0);
        for(int num: nums)
        {
            pos[num] = i;
            i++;
        }

        std::sort(nums.begin(), nums.end());
        if(nums[i - 1] >= 2 * nums[i - 2])
        {
            return pos[nums[i - 1]];
        }
        return -1;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {3,6,1,0};
        int res = 1;
        assert(sol.dominantIndex(nums) == res);
    }
    {
        std::vector<int> nums = {1,2,3,4};
        int res = -1;
        assert(sol.dominantIndex(nums) == res);
    }
    return 0;
}