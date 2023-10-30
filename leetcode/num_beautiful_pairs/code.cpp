#include <iostream>
#include <assert.h>

#include <vector>
#include <cmath>

class Solution {
    int gcd(int a, int b)
    {
        if(b == 0)
        {
            return a;
        }
        return gcd(b, a % b);
    }
public:
    int countBeautifulPairs(std::vector<int>& nums) 
    {
        int res = 0;
        int n = nums.size();

        for(int i = 0; i < n; i++)
        {
            for(int j = i + 1; j < n; j++)
            {
                int exp = std::log10(nums[i]);
                int a = nums[i] / std::pow(10, exp);
                int b = nums[j] % 10;
                if(gcd(a, b) == 1)
                {
                    res++;
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
        std::vector<int> nums = {2,5,1,4};
        int res = 5;
        assert(sol.countBeautifulPairs(nums) == res);
    }
    {
        std::vector<int> nums = {11,21,12};
        int res = 2;
        assert(sol.countBeautifulPairs(nums) == res);
    }
    return 0;
}