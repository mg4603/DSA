#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    int countQuadruplets(std::vector<int>& nums) {
        int res = 0;
        for(int i = 0; i < nums.size() - 3; i++)
        {
            int a = nums[i];
            for(int j = i + 1; j < nums.size() - 2; j++)
            {
                int ab = a + nums[j];
                for(int k = j + 1; k < nums.size() - 1; k++)
                {
                    int abc = ab + nums[k];
                    for(int p = k + 1; p < nums.size(); p++)
                    {
                        if(abc == nums[p])
                        {
                            res++;
                        }
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
        std::vector<int> nums = {1,2,3,6};
        int res = 1;
        assert(sol.countQuadruplets(nums) == res);
    }
    {
        std::vector<int> nums = {3,3,6,4,5};
        int res = 0;
        assert(sol.countQuadruplets(nums) == res);
    }
    {
        std::vector<int> nums = {1,1,1,3,5};
        int res = 4;
        assert(sol.countQuadruplets(nums) == res);
    }
    return 0;
}