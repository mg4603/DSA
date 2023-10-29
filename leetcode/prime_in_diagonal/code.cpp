#include <iostream>
#include <assert.h>

#include <vector>
#include <cmath>

class Solution {
    bool isPrime(int num)
    {
        if(num < 2)
        {
            return false;
        }

        for(int i = 2; i <= std::sqrt(num); i++)
        {
            if(num % i == 0)
            {
                return false;
            }
        }
        return true;
    }
public:
    int diagonalPrime(std::vector<std::vector<int>>& nums) 
    {
        int res = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++)
        {
            int temp = isPrime(nums[i][i]) ? nums[i][i] : 0;
            int temp2 = isPrime(nums[i][n - i - 1]) ? nums[i][n - i - 1]: 0;

            if(temp > res)
            {
                res = temp;
            }
            if(temp2 > res)
            {
                res = temp2;
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<std::vector<int>> nums = {
            {1,2,3},{5,6,7},{9,10,11},};
        int res = 11;
        assert(sol.diagonalPrime(nums) == res);
    }
    {
        std::vector<std::vector<int>> nums = {
            {1,2,3},{5,17,7},{9,11,10},};
        int res = 17;
        assert(sol.diagonalPrime(nums) == res);
    }
    return 0;
}