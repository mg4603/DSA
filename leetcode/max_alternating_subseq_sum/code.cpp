#include <iostream>
#include <assert.h>

#include <vector>

class Solution {

    long long helper(std::vector<int> &nums, int i, bool plus, 
            std::vector<std::vector<long long>> &memo, int n) {
        if(i == n)return 0LL;
        if(memo[i][(plus? 1: 0)])return memo[i][(plus? 1: 0)];
        long long res = std::max(
                helper(nums, i + 1, plus, memo, n), 
                (plus? 1: -1) * nums[i] + 
                helper(nums, i + 1, !plus, memo, n));

        memo[i][(plus? 1 : 0)] = res;
        return res;
    }
public:
    long long maxAlternatingSum(std::vector<int>& nums) {
        std::ios::sync_with_stdio(0);
        int n = nums.size();
        std::vector<std::vector<long long>> memo(n, 
                        std::vector<long long>(2, 0ll));
        return helper(nums, 0, true, memo, n);
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {4,2,5,3};
        int res = 7;
        assert(sol.maxAlternatingSum(nums) == res);
    }
    return 0;
}