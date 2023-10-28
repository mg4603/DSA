#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    int differenceOfSum(std::vector<int>& nums) 
    {
        std::ios_base::sync_with_stdio(0);
        int res = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            int temp = nums[i];
            res += temp;
            while(temp)
            {
                res -= (temp % 10);
                temp /= 10;
            }
        }
        return res;    
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {1,15,6,3};
        int res = 9;
        assert(sol.differenceOfSum(nums) == res);
    }
    {
        std::vector<int> nums = {1,2,3,4};
        int res = 0;
        assert(sol.differenceOfSum(nums) == res);
    }
    return 0;
}