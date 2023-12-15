#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    int totalHammingDistance(std::vector<int>& nums) 
    {
        int n = nums.size();
        int res = 0;
        
        for(int i = 0; i < 32; i++)
        {
            int cnt = 0;
            for(int j = 0; j < n; j++)
            {
                cnt +=(nums[j]>>i)&1;
            }
            res += (cnt * (n-cnt));
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {4,14,2};
        int res = 6;
        assert(sol.totalHammingDistance(nums) == res);
    }
    {
        std::vector<int> nums = {4,14,4};
        int res = 4;
        assert(sol.totalHammingDistance(nums) == res);
    }
    return 0;
}