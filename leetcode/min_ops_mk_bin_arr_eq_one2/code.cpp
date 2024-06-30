#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    int minOperations(std::vector<int>& nums) {
        std::ios::sync_with_stdio(0);
        int res = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            if(nums[i] ^ (res % 2) == 0) {
                res++;
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {0,1,1,0,1};
        int res = 4;
        assert(sol.minOperations(nums) == res);
    }
    return 0;
}