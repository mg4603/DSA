#include <iostream>
#include <assert.h>

#include <vector>
#include <set>

class Solution {
    bool equalMaxDigits(int a, int b)
    {
        int max_a(0);
        while(a)
        {
            if(a % 10 > max_a)
            {
                max_a = a % 10;
            }
            a /= 10;
        }
        int max_b(0);
        while(b)
        {
            if(b % 10 > max_b)
            {
                max_b = b % 10;
            }
            b /= 10;
        }
        return max_a == max_b;
    }
public:
    int maxSum(std::vector<int>& nums) {
        std::set<int> pair_sums;
        for(int i(nums.size() - 1); i >= 0; i--)
        {
            for(int j(i - 1); j >= 0; j--)
            {
                if(equalMaxDigits(nums[i], nums[j]))
                {
                    pair_sums.insert(nums[i] + nums[j]);
                }
            }
        }
        if(pair_sums.size() == 0)
        {
            return -1;
        }
        return *(pair_sums.rbegin());
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {51,71,17,24,42};
        assert(sol.maxSum(nums) == 88);
    }
    {
        std::vector<int> nums = {1,2,3,4};
        assert(sol.maxSum(nums) == -1);
    }
    return 0;
}