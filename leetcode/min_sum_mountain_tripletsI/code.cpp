#include <iostream>
#include <assert.h>

#include <vector>
#include <limits>

class Solution {
public:
    int minimumSum(std::vector<int>& nums) 
    {
        int res = std::numeric_limits<int>::max();
        int n = nums.size();

        for(int i = 0; i < n - 2; i++)
        {
            int num_i = nums[i];
            for(int j = i + 1; j < n - 1; j++)
            {
                int num_j = nums[j];
                for(int k = j + 1; k < n; k++)
                {
                    if(num_i < num_j && num_j > nums[k])
                    {
                       int temp = num_i + num_j + nums[k];

                       if(temp < res)
                       {
                           res = temp;
                       } 
                    }
                }
            }
        }

        if(res == std::numeric_limits<int>::max())
        {
            return -1;
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {8,6,1,5,3};
        int res = 9;
        assert(sol.minimumSum(nums) == res);
    }
    {
        std::vector<int> nums = {5,4,8,7,10,2};
        int res = 13;
        assert(sol.minimumSum(nums) == res);
    }
    {
        std::vector<int> nums = {6,5,4,3,4,5};
        int res = -1;
        assert(sol.minimumSum(nums) == res);
    }
    return 0;
}