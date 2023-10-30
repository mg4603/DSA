#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    int semiOrderedPermutation(std::vector<int> &nums) 
    {
        std::ios_base::sync_with_stdio(0);
        int n = nums.size();
        int pos_n, pos_one;
        for(int i = 0; i < n; i++)
        {
            if(nums[i] == 1)
            {
                pos_one = i;
            }
            else if (nums[i] == n)
            {
                pos_n = i;
            }
        }

        int res = ((n - 1) - pos_n) + pos_one;
        if(pos_one > pos_n)
        {
            res--;
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {2,1,4,3};
        int res = 2;
        assert(sol.semiOrderedPermutation(nums) == res);
    }
    {
        std::vector<int> nums = {2,4,1,3};
        int res = 3;
        assert(sol.semiOrderedPermutation(nums) == res);
    }
    {
        std::vector<int> nums = {1,3,4,2,5};
        int res = 0;
        assert(sol.semiOrderedPermutation(nums) == res);
    }
    return 0;
}