#include <iostream>
#include <assert.h>

#include <vector>
#include <cmath>

class Solution {
public:
    int findKOr(std::vector<int>& nums, int k) 
    {
        std::ios_base::sync_with_stdio(0);
        
        std::vector<int> bits(32, 0);

        for(int i = 0; i < nums.size(); i++)
        {
            int pos = 0;
            while(nums[i])
            {
                if(nums[i] % 2 == 1)
                {
                    bits[pos]++;
                }
                nums[i] /= 2;
                pos++;                
            }
        } 

        int res = 0;
        for(int i = 0; i < 32; i++)
        {
            if(bits[i] >= k)
            {
                res += std::pow(2, i);
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {7,12,9,8,9,15};
        int k = 4;
        int res = 9;
        assert(sol.findKOr(nums, k) == res);
    }
    {
        std::vector<int> nums = {2,12,1,11,4,5};
        int k = 6;
        int res = 0;
        assert(sol.findKOr(nums, k) == res);
    }
    {
        std::vector<int> nums = {10,8,5,9,11,6,8};
        int k = 1;
        int res = 15;
        assert(sol.findKOr(nums, k) == res);
    }
    return 0;
}