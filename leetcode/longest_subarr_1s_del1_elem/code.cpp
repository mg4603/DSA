#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    int longestSubarray(std::vector<int>& nums) {
        int res = 0;
        int n = nums.size();

        int j = 0;
        int cnt = 0;

        for(int i = 0; i < n; i++)
        {
            if(nums[i] == 0)cnt++;
            while(cnt > 1)
            {
                if(nums[j] == 0)cnt--;
                j++;
            }

            res = std::max(res, i - j + 1);
        }
        return res == 0 ? res: res - 1;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {0,1,1,1,0,1,1,0,1};
        int res = 5;
        assert(sol.longestSubarray(nums) == res);
    }
    return 0;
}