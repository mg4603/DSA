#include <iostream>
#include <assert.h>

#include <cmath>

class Solution {
public:
    int findNthDigit(int n) 
    {
      int tier = 1;
      int nums_in_tier = 9;

      while(n - (long)tier * nums_in_tier > 0)
      {
        n -= (tier * nums_in_tier);
        nums_in_tier *= 10;
        tier++;
      }

      int num = std::pow(10, tier - 1) + (n - 1) / tier;
      return std::to_string(num)[(n - 1)%tier] - '0';
    }
};

int main()
{
    Solution sol;
    {
        int n = 3;
        int res = 3;
        assert(sol.findNthDigit(n) == res);
    }
    {
        int n = 11;
        int res = 0;
        assert(sol.findNthDigit(n) == res);
    }
    return 0;
}