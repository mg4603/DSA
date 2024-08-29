#include <iostream>
#include <assert.h>

#include <vector>
#include <algorithm>

class Solution {
public:
    int maximizeGreatness(std::vector<int>& nums) {
        std::ios::sync_with_stdio(0);
        std::sort(nums.begin(), nums.end());
        int res = 0, i = 0, j = 0;
        int n = nums.size();

        while(i < n && j < n) {
            if(nums[i] >= nums[j]) {
                j++;
                continue;
            }    
            res++;
            i++;
            j++;
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {1,3,5,2,1,3,1};
        int res = 4;
        assert(sol.maximizeGreatness(nums) == res);
    }
    return 0;
}