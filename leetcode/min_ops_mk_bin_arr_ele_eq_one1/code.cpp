#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    int minOperations(std::vector<int>& nums) {
        std::ios::sync_with_stdio(0);
        int n = nums.size();
        int res = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] == 0 && i + 3 <= n) {
                for(int j = i; j < i + 3; j++) {
                    nums[j] ^= 1;
                }
                res++;
            }
        }
        for(int i = n - 3; i < n; i++) {
            if(nums[i] == 0)return -1;
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {0,1,1,1,0,0};
        int res = 3;
        assert(sol.minOperations(nums) == res);
    }
    return 0;
}