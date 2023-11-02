#include <iostream>
#include <assert.h>

#include <vector>
#include <algorithm>

class Solution {
public:
    void nextPermutation(std::vector<int>& nums) 
    {
        int n = nums.size();
        int i = n - 2;
        while(i >= 0)
        {
            if(i + 1 < n && nums[i] < nums[i + 1])
            {
                break;
            }
            i--;
        }
        if(i == -1)
        {
            std::reverse(nums.begin(), nums.end());
        }
        else
        {
            for(int j = n - 1; j > i; j--)
            {
                if(nums[j] > nums[i])
                {
                    std::swap(nums[i], nums[j]);
                    std::reverse(nums.begin() + i + 1, nums.end());
                    break;
                }
            }
        }
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {1,2,3};
        std::vector<int> res = {1,3,2};
        sol.nextPermutation(nums);
        assert(nums == res);
    }
    {
        std::vector<int> nums = {3,2,1};
        std::vector<int> res = {1,2,3};
        sol.nextPermutation(nums);
        assert(nums == res);
    }
    {
        std::vector<int> nums = {1,1,5};
        std::vector<int> res = {1,5,1};
        sol.nextPermutation(nums);
        assert(nums == res);
    }
    return 0;
}