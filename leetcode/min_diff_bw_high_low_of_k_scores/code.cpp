#include <iostream>
#include <assert.h>

#include <vector>
#include <algorithm>

class Solution {
public:
    int minimumDifference(std::vector<int>& nums, int k) 
    {
        std::ios_base::sync_with_stdio(0);
        if(nums.size() == 1 || k == 1)
        {
            return 0;
        }
        std::sort(nums.begin(), nums.end());
        int res = 100001;
        for(int i = 0; i + k - 1 < nums.size(); i++)
        {
            int temp = nums[i + k - 1] - nums[i];
            if(temp < res)
            {
                res = temp;
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {90};
        int k = 1;
        int res = 0;
        assert(sol.minimumDifference(nums, k) == res);
    }
    {
        std::vector<int> nums = {9,4,1,7};
        int k = 2;
        int res = 2;
        assert(sol.minimumDifference(nums, k) == res);
    }
    return 0;
}