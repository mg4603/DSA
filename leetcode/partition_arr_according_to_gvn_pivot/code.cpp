#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    std::vector<int> pivotArray(std::vector<int>& nums, int pivot) {
        std::ios::sync_with_stdio(0);
        int n = nums.size();
        
        int low = 0;
        int same = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] < pivot) {
                low++;
            }
            if(nums[i] == pivot) {
                same++;
            }
        }

        int high = low + same;
        same = low;
        low = 0;
        std::vector<int> res(n);
        for(int i = 0; i < n; i++) {
            if(nums[i] < pivot) {
                res[low++] = nums[i];
            }
            else if(nums[i] == pivot) {
                res[same++] = pivot;
            }
            else {
                res[high++] = nums[i];
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {9,12,5,10,14,3,10};
        int pivot = 10;
        std::vector<int> res = {9,5,3,10,10,12,14};
        assert(sol.pivotArray(nums, pivot) == res);
    }
    return 0;
}