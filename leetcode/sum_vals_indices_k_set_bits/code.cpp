#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
    int countSetBits(int n)
    {
        int count = 0;
        while(n)
        {
            n &= (n - 1);
            count++;
        }
        return count;
    }
public:
    int sumIndicesWithKSetBits(std::vector<int>& nums, int k) {
        int res = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(countSetBits(i) == k)
            {
                res += nums[i];
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {5,10,1,5,2};
        int k = 1;
        int res = 13;
        assert(sol.sumIndicesWithKSetBits(nums, k) == res);
    }
    {
        std::vector<int> nums = {4,3,2,1};
        int k = 2;
        int res = 1;
        assert(sol.sumIndicesWithKSetBits(nums, k) == res);
    }
    return 0;
}