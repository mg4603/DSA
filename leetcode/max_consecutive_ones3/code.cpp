#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    int longestOnes(std::vector<int>& nums, int k) {
        int i = 0;
        int j = 0;
        while(i < nums.size())
        {
            if(nums[i] == 0)
            {
                k--;
            }
            if(k < 0)
            {
                if(nums[j] == 0)
                {
                    k++;
                }
                j++;
            }
            i++;
        }
        return i - j;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {1,1,1,0,0,0,1,1,1,1,0};
        int k = 2;
        int res = 6;
        assert(sol.longestOnes(nums, k) == res);
    }
    return 0;
}