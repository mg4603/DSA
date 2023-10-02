#include <iostream>
#include <assert.h>

#include <vector>
#include <algorithm>

class Solution {
public:
    int smallestRangeI(std::vector<int>& nums, int k) {
        std::sort(nums.begin(), nums.end());
        int smallest(nums[0]);
        int largest(nums.back());

        int mid((smallest + largest) / 2);

        return largest - std::min(k, largest - mid) - smallest 
                    - std::min(k, mid - smallest);
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {1};
        int k = 0;
        assert(sol.smallestRangeI(nums, k) == 0);
    }
    {
        std::vector<int> nums = {0, 10};
        int k = 2;
        assert(sol.smallestRangeI(nums, k) == 6);
    }
    {
        std::vector<int> nums = {1, 3 , 6};
        int k = 3;
        assert(sol.smallestRangeI(nums, k) == 0);
    }
    return 0;
}