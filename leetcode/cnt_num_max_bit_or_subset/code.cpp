#include <iostream>
#include <assert.h>

#include <vector>
#include <numeric>

class Solution {
    int help(std::vector<int> &nums, int i, 
                int tgt, int curr) {
        if(i == nums.size())return 0;

        int res = (tgt == (curr | nums[i]));
        int without = help(nums, i + 1, tgt, curr);
        int with = help(nums, i + 1, tgt, curr | nums[i]);
        return res + with + without;
    }
public:
    int countMaxOrSubsets(std::vector<int>& nums) {
        std::ios::sync_with_stdio(0);
        int n = nums.size();
        int tgt = std::accumulate(nums.begin(), 
                    nums.end(), 0, [](int a, int b) {
            return a | b;
        });

        return help(nums, 0, tgt, 0);
        
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {3, 1};
        int res = 2;
        assert(sol.countMaxOrSubsets(nums) == res);
    }
    return 0;
}