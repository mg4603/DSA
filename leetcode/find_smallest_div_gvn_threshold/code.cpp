#include <iostream>
#include <assert.h>

#include <vector>
#include <algorithm>

class Solution {
public:
    int smallestDivisor(std::vector<int>& nums, int threshold) {
        std::ios::sync_with_stdio(0);
        int r = *std::max_element(nums.begin(), nums.end());
        int l = 1;
        while(l < r) {
            int sum = 0;
            int mid = (l + r) / 2;

            for(int j = 0; j < nums.size(); j++) {
                sum += (nums[j] / mid);
                if(1.0 * nums[j] / mid > nums[j] / mid) {
                    sum++;
                }
            }
            
            if(sum <= threshold) {
                r = mid;
            }else {
                l = mid + 1;
            }
        }
        return l;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {1,2,5,9};
        int threshold = 6, res = 5;
        assert(sol.smallestDivisor(nums, threshold) == res);
    }
    return 0;
}