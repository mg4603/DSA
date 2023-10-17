#include <iostream>
#include <assert.h>

#include <vector>
#include <numeric>

class Solution {
public:
    bool kLengthApart(std::vector<int>& nums, int k) {
        std::ios_base::sync_with_stdio(0);

        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == 0)
            continue;
            
            int end = std::min(static_cast<int>(nums.size()), i + k + 1);;
            if(std::accumulate(nums.begin() + i, nums.begin() + end, 0) > 1)
            {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {1,0,0,0,1,0,0,1};
        int k = 2;
        bool res = true;
        assert(sol.kLengthApart(nums, k) == res);
    }
    {
        std::vector<int> nums = {1,0,0,1,0,1};
        int k = 2;
        bool res = false;
        assert(sol.kLengthApart(nums, k) == res);
    }
    return 0;
}