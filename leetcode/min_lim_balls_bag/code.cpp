#include <iostream>
#include <assert.h>

#include <vector>
#include <algorithm>

class Solution {
public:
    int minimumSize(std::vector<int>& nums, int maxOperations) {
        std::ios::sync_with_stdio(0);
        int r = *std::max_element(nums.begin(), nums.end());
        int l = 1;
        while(l < r) {

            int count = 0;
            int mid = (l + r) / 2;
            
            for(int num: nums) {
                count += (num - 1) / mid;
            }

            if(count > maxOperations) {
                l = mid + 1;
            }else {
                r = mid;
            }
        }
        return l;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {9};
        int maxOperations = 2, res = 3;
        assert(sol.minimumSize(nums, maxOperations) == res);
    }
    return 0;
}