#include <iostream>
#include <assert.h>

#include <vector>
#include <numeric>

class Solution {
public:
    int minSwaps(std::vector<int>& nums) {
        int ones = std::accumulate(nums.begin(), nums.end(), 0);

        int cnt = std::accumulate(nums.begin(), nums.begin() + ones, 0);
        int res = ones - cnt;
        int n = nums.size();

        for(int i = 0; i < n; i++)
        {
            cnt += nums[(i + ones) % n];
            cnt -= nums[i];
            res = std::min(res, ones - cnt);
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {0,1,0,1,1,0,0};
        int res = 1;
        assert(sol.minSwaps(nums) == res);
    }
    return 0;
}