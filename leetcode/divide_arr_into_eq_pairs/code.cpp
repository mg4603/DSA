#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    bool divideArray(std::vector<int>& nums) 
    {
        std::vector<int> freq(501, 0);
        for(int i = 0; i < nums.size(); i++)
        {
            freq[nums[i]]++;
        }
        for(int i = 0; i < 501; i++)
        {
            if(!freq[i])continue;
            if(freq[i] % 2 == 1)
            {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {3,2,3,2,2,2};
        bool res = 1;
        assert(sol.divideArray(nums) == res);
    }
    {
        std::vector<int> nums = {1,2,3,4};
        bool res = 0;
        assert(sol.divideArray(nums) == res);
    }
    return 0;
}