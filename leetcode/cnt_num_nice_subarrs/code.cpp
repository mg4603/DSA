#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    int numberOfSubarrays(std::vector<int>& nums, int k) 
    {
        int res = 0;
        int j = 0;
        int count = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] & 1)
            {
                k--;
                if(k <= 0)
                {
                    count = 1;
                    while(!(nums[j++] & 1))count++;
                    res += count;
                }
            }
            else if(k <= 0)res += count;
            
        }
        return res;    
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {1,1,2,1,1};
        int k = 3;
        int res = 2;
        assert(sol.numberOfSubarrays(nums, k) == res);
    }
    return 0;
}