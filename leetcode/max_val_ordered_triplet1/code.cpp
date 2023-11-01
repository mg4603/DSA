#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    long long maximumTripletValue(std::vector<int>& nums) 
    {
        long long res = 0;
        int n = nums.size();

        for(int i = 0; i < n; i++)
        {
            for(int j = i + 1; j < n; j++)
            {
                for(int k = j + 1; k < n; k++)
                {
                    long long temp = (static_cast<long long>(nums[i]) - 
                                        nums[j]) * nums[k];
                    if(temp > res)
                    {
                        res = temp;
                    }
                }
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {12,6,1,2,7};
        int res = 77;
        assert(sol.maximumTripletValue(nums) == res);
    }
    {
        std::vector<int> nums = {1,10,3,4,19};
        int res = 133;
        assert(sol.maximumTripletValue(nums) == res);
    }
    {
        std::vector<int> nums = {1,2,3};
        int res = 0;
        assert(sol.maximumTripletValue(nums) == res);
    }
    return 0;
}