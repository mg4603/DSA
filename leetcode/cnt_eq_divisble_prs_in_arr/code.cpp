#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    int countPairs(std::vector<int>& nums, int k) 
    {
        int res = 0;
        for(int i = 0; i < nums.size(); i ++)
        {
            for(int j = i + 1; j < nums.size(); j++)
            {
                if((i * j) % k != 0)continue;
                if(nums[i] == nums[j])res++;
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {3,1,2,2,2,1,3};
        int k = 2;
        int res = 4;
        assert(sol.countPairs(nums, k) == res);
    }
    {
        std::vector<int> nums = {1,2,3,4};
        int k = 1;
        int res = 0;
        assert(sol.countPairs(nums, k) == res);
    }
    return 0;
}