#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    int countMatchingSubarrays(std::vector<int>& nums, 
                            std::vector<int>& pattern) {
        std::ios::sync_with_stdio(0);
        int res = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            int j = 0;
            for(; i + j + 1 < n && j < pattern.size(); j++) {
                if((pattern[j] == -1 && 
                    nums[i + j + 1] >= nums[i + j]) || 
                 (pattern[j] == 0 && 
                    nums[i + j + 1] != nums[i + j]) || 
                 (pattern[j] == 1 && 
                    nums[i + j + 1] <= nums[i + j]))break;
            }
            if(j == pattern.size())res++;
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {1,2,3,4,5,6};
        std::vector<int> pattern = {1,1};
        int res = 4;
        assert(sol.countMatchingSubarrays(nums, pattern) == res);
    }
    return 0;
}