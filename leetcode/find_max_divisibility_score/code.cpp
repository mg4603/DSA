#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    int maxDivScore(std::vector<int>& nums, std::vector<int>& divisors) 
    {
        int res = divisors[0];
        int max_divisor_score = 0;

        for(int i = 0; i < divisors.size(); i++)
        {
            int divisor_score = 0;
            int divisor = divisors[i];
            for(int j = 0; j < nums.size(); j++)
            {
                if(nums[j] % divisor == 0)
                {
                    divisor_score++;
                }
            }
            if(divisor_score > max_divisor_score)
            {
                max_divisor_score = divisor_score;
                res = divisor;
            }
            else if(divisor_score == max_divisor_score)
            {
                if(res > divisor)
                {
                    res = divisor;
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
        std::vector<int> nums = {4,7,9,3,9};
        std::vector<int> divisors = {5,2,3};
        int res = 3;
        assert(sol.maxDivScore(nums, divisors) == res);
    }
    {
        std::vector<int> nums = {20,14,21,10};
        std::vector<int> divisors = {5,7,5};
        int res = 5;
        assert(sol.maxDivScore(nums, divisors) == res);
    }
    {
        std::vector<int> nums = {12};
        std::vector<int> divisors = {10,16};
        int res = 10;
        assert(sol.maxDivScore(nums, divisors) == res);
    }
    return 0;
}