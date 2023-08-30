#include <iostream>
#include <assert.h>

#include <cmath>

class Solution {
public:
    bool isUgly(long long n) {
        if(n == 1)
        {
            return true;
        }
        if(n <= 0)
        {
            return false;
        }

        if(n < 0)
        {
            n = -n;
        }

        int num_twos(0);
        int num_threes(0);
        int num_fives(0);

        long long initial_num(n);

        while(n % 2 == 0)
        {
            n /= 2;    
            num_twos++;
        }

        while(n % 3 == 0)
        {
            n /= 3;
            num_threes++;
        }

        while(n % 5 == 0)
        {
            n/=5;
            num_fives++;
        }

        if(std::pow(2, num_twos) * std::pow(3, num_threes) * std::pow(5, num_fives) < initial_num )
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
        assert(sol.isUgly(6) == true);
        assert(sol.isUgly(1) == true);
        assert(sol.isUgly(14) == false);
        assert(sol.isUgly(-2147483648) == false);
    }
    return 0;
}