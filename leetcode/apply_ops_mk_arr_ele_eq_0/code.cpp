#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    bool checkArray(std::vector<int>& nums, int k) {
        int n = nums.size();
        int curr = 0;
        for(int i = 0; i < n; i++)
        {
            if(curr > nums[i])return false;
            nums[i] -= curr;
            curr += nums[i];
            if(i >= k - 1)
            {
                curr -= nums[i - k + 1];
            }            
        }
        return curr == 0;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {2,2,3,1,1,0};
        int k = 3;
        bool res = true;
        assert(sol.checkArray(nums, k) == res);
    }
    return 0;
}