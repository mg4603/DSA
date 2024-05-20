#include <iostream>
#include <assert.h>

#include <algorithm>
#include <vector>

class Solution {
public:
    int partitionArray(std::vector<int> &nums, int k) {
        std::ios::sync_with_stdio(0);
        std::sort(nums.begin(), nums.end());
        int res = 1;
        int start = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] - start > k) {
                start = nums[i];
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
        std::vector<int> nums = {3,6,1,2,5};
        int k = 2;
        int res = 2;
        assert(sol.partitionArray(nums, k) == res);
    }
    return 0;
}