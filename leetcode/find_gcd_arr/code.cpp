#include <iostream>
#include <assert.h>

#include <vector>

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
    int findGCD(std::vector<int>& nums) {
        std::ios_base::sync_with_stdio(0);
        int largest = 0;
        int smallest = 1001;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] < smallest)
            {
                smallest = nums[i];
            }
            if(nums[i] > largest)
            {
                largest = nums[i];
            }
        }
        return gcd(largest, smallest);
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {2,5,6,9,10};
        int res = 2;
        assert(sol.findGCD(nums) == res);
    }
    {
        std::vector<int> nums = {7,5,6,8,3};
        int res = 1;
        assert(sol.findGCD(nums) == res);
    }
    {
        std::vector<int> nums = {3,3};
        int res = 3;
        assert(sol.findGCD(nums) == res);
    }
    return 0;
}