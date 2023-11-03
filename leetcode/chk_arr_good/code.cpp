#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    bool isGood(std::vector<int>& nums) 
    {

        std::ios_base::sync_with_stdio(0);
        const int n = nums.size();
        std::vector<int> freq(n, 0);

        for(int i = 0; i < n; i++)
        {
            if(nums[i] >= n)
            {
                return false;
            }

            int temp = ++freq[nums[i]];
            if(temp != 1 && nums[i] != n - 1)
            {
                return false;
            }
        }

        if(freq[n-1] != 2)
        {
            return false;
        }
        return true;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {2, 1, 3};
        int res = false;
        assert(sol.isGood(nums) == res);
    }
    {
        std::vector<int> nums = {1, 3, 3, 2};
        int res = true;
        assert(sol.isGood(nums) == res);
    }
    {
        std::vector<int> nums = {1, 1};
        int res = true;
        assert(sol.isGood(nums) == res);
    }
    {
        std::vector<int> nums = {3, 4, 4, 1, 2, 1};
        int res = false;
        assert(sol.isGood(nums) == res);
    }
    return 0;
}