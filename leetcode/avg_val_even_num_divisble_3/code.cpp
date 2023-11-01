#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    int averageValue(std::vector<int>& nums) 
    {
        int sum = 0;
        int cnt = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] % 6 == 0)
            {
                sum += nums[i];
                cnt++;
            }
        }
        if(cnt == 0)
        {
            return 0;
        }
        return sum / cnt;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {1,3,6,10,12,15};
        int res = 9;
        assert(sol.averageValue(nums) == res);
    }
    {
        std::vector<int> nums = {1,2,4,7,10};
        int res = 0;
        assert(sol.averageValue(nums) == res);
    }
    return 0;
}