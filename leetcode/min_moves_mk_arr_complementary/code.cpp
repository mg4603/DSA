#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    int minMoves(std::vector<int>& nums, int limit) {
        int n = nums.size();
        std::vector<int> memo(2 * limit + 2, 0);
        for(int i = 0; i < n / 2; i++)
        {
            int l = nums[i];
            int r = nums[n - 1 - i];
            memo[std::min(l, r) + 1]--;
            memo[l + r]--;
            memo[l + r + 1]++;
            memo[std::max(l, r) + limit + 1]++;
        }
        int res = n;
        int curr = n;

        for(int i = 2; i <= limit * 2; i++)
        {
            curr += memo[i];
            res = std::min(curr, res);
        }

        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {1,2,4,3};
        int limit = 4;
        int res = 1;
        assert(sol.minMoves(nums, limit) == res);
    }
    return 0;
}