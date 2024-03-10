#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    int longestNiceSubarray(std::vector<int>& nums) {
        int used_bits = 0;
        int j = 0;
        int res = 0;
        int n = nums.size();

        for(int i = 0; i < n; i++)
        {
            while((used_bits & nums[i]) != 0)
                used_bits ^= nums[j++];
            used_bits |= nums[i];

            res = std::max(res, i - j + 1);
        }

        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {1,3,8,48,10};
        int res = 3;
        assert(sol.longestNiceSubarray(nums) == res);
    }
    return 0;
}