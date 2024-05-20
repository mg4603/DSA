#include <iostream>
#include <assert.h>

#include <vector>
#include <algorithm>

class Solution {
public:
    int reductionOperations(std::vector<int>& nums) {
        std::ios::sync_with_stdio(0);
        std::sort(nums.begin(), nums.end());
        int res = 0;
        int cnt = 1;
        for(int i = nums.size() - 2; i >= 0; i--) {
            if(nums[i] == nums[i + 1]) {
                cnt++;
            }else {
                res += cnt;
                cnt++;
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {5,1,3};
        int res = 3;
        assert(sol.reductionOperations(nums) == res);
    }
    return 0;
}