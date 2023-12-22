#include <iostream>
#include <assert.h>

#include <vector>
#include <algorithm>

class Solution {
public:
    int triangleNumber(std::vector<int>& nums) 
    {
        std::sort(nums.begin(), nums.end());
        int n = nums.size();
        int res = 0;

        for(int i = 0; i < n - 2; i++)
        {
            int k = i + 2;
            for(int j = i + 1; j < n && nums[i] != 0; j++)
            {
                while(k < n && nums[i] + nums[j] > nums[k])
                {
                    k++;
                }
                res += k - j - 1;
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {2,2,3,4};
        int res = 3;
        assert(sol.triangleNumber(nums) == res);
    }
    {
        std::vector<int> nums = {4,2,3,4};
        int res = 4;
        assert(sol.triangleNumber(nums) == res);
    }
    return 0;
}