#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    int triangularSum(std::vector<int>& nums) {
        std::ios::sync_with_stdio(0);
        int n = nums.size();
        while(n > 1) {
            for(int i = 0; i < n - 1; i++) {
                nums[i] = (nums[i] + nums[i + 1]) % 10;
            }
            n--;
        }
        return nums[0];
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {1,2,3,4,5};
        int res = 8;
        assert(sol.triangularSum(nums) == res);
    }
    return 0;
}