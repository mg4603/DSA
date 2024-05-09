#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    int maximumXOR(std::vector<int>& nums) {
        std::ios::sync_with_stdio(0);
        int res = 0;
        for(int i = 0; i < nums.size(); i++) {
            res |= nums[i];
        }

        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {3,2,4,6};
        int res = 7;
        assert(sol.maximumXOR(nums) == res);
    }
    return 0;
}