#include <iostream>
#include <assert.h>

#include <algorithm>
#include <vector>

class Solution {
public:
    int maxFrequency(std::vector<int>& nums, int k) {
        std::sort(nums.begin(), nums.end());
        int n = nums.size();
        int res = 1;
        std::sort(nums.begin(), nums.end());
        long long sum = 0LL;
        int j = 0;
        for(int i = 0; i < n; i++)
        {
            sum += nums[i];
            while(j < n && 1LL * (i - j + 1) * 
                        nums[i] - sum > k)sum -= nums[j++];
            res = std::max(res, i - j + 1);
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {1,2,4};
        int k = 5;
        int res = 3;
        assert(sol.maxFrequency(nums, k) == res);
    }
    return 0;
}