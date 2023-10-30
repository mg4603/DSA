#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    int longestAlternatingSubarray(std::vector<int>& nums, int threshold) 
    {
        int res = 0;
        int cnt = 0;
        int parity = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] % 2 == 0 && nums[i] <= threshold)
            {
                cnt++;
                i++;
                while(i < nums.size())
                {
                    parity ^= 1;
                    if(nums[i] % 2 != parity || nums[i] > threshold)
                    {
                        break;
                    }
                    i++;
                    cnt++;
                }

                if(cnt > res)
                {
                    res = cnt;
                }
                cnt = 0;
                parity = 0;
                i--;
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {1,2};
        int threshold = 2;
        int res = 1;
        assert(sol.longestAlternatingSubarray(nums, threshold) == res);
    }
    {
        std::vector<int> nums = {2,3,4,5};
        int threshold = 4;
        int res = 3;
        assert(sol.longestAlternatingSubarray(nums, threshold) == res);
    }
    return 0;
}