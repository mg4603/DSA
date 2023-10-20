#include <iostream>
#include <assert.h>

#include <vector>
#include <algorithm>

class Solution {
    
public:
    int specialArray(std::vector<int>& nums) {
        
        std::sort(nums.begin(), nums.end());
        int ptr = 0;
        int n = nums.size();
        for(int i = 0; i <= nums.back(); i++)
        {
            while(nums[ptr] < i)
            {
                ptr++;
            }
            if(n - ptr == i)
            {
                return i;
            }


        }
        return -1;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {3,5};
        int res = 2;
        assert(sol.specialArray(nums) == res);
    }
    {
        std::vector<int> nums = {0,0};
        int res = -1;
        assert(sol.specialArray(nums) == res);
    }
    {
        std::vector<int> nums = {0,4,3,0,4};
        int res = 3;
        assert(sol.specialArray(nums) == res);
    }
    return 0;
}