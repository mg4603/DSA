#include <iostream>
#include <assert.h>

#include <vector>
#include <numeric>

class Solution {
public:
    std::vector<int> getSumAbsoluteDifferences(std::vector<int>& nums) {
        std::ios::sync_with_stdio(0);
        long long postSum = std::accumulate(nums.begin(), nums.end(), 0LL);
        int n = nums.size();
        std::vector<int> res(n);
        long long preSum = 0LL;
        for(int i = 0; i < n; i++)
        {
            res[i] += postSum - 1LL * (n - i) * nums[i];
            res[i] += 1LL * i * nums[i] - preSum;
            postSum -= nums[i];
            preSum += nums[i];
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {2,3,5};
        std::vector<int> res = {4,3,5};
        assert(sol.getSumAbsoluteDifferences(nums) == res);
    }
    return 0;
}