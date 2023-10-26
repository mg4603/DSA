#include <iostream>
#include <assert.h>

#include <cmath>

class Solution {
public:
    int divisorSubstrings(int num, int k) 
    {
        int res = 0;
        std::string num_str = std::to_string(num);
        int divisor = 0;
        for(int i = 0; i < k; i++)
        {
            divisor *= 10;
            divisor += (num_str[i] - '0');
        }
        for(int i = k; i < num_str.length(); i++)
        {
            if(divisor && num % divisor == 0)res++;
            
            divisor %= static_cast<int>(std::pow(10, k - 1));
            divisor *= 10;
            divisor += (num_str[i] - '0');
        }
        if(divisor && num % divisor == 0)
        {
            res++;
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        int num = 240;
        int k = 2;
        int res = 2;
        assert(sol.divisorSubstrings(num, k) == res);
    }
    {
        int num = 430043;
        int k = 2;
        int res = 2;
        assert(sol.divisorSubstrings(num, k) == res);
    }
    return 0;
}