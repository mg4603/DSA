#include <iostream>
#include <assert.h>

#include <vector>
#include <cmath>

class Solution {
    std::vector<bool> getSieve(int n)
    {
        std::vector<bool> sieve = std::vector<bool>(n + 1, true);
        sieve[0] = sieve[1] = false;
        for(int i(2); i < n + 1; i++)
        {
            if(sieve[i] != true)
            {
                continue;
            }
            for(int j(i * 2); j < n + 1; j += i)
            {
                sieve[j] = false;
            }
        }
        return sieve;

    }
public:
    int countPrimeSetBits(int left, int right) {
        int n = std::floor(std::log2(right)) + 1;
        std::vector<bool> sieve = getSieve(n);
        int res(0);

        for(int i(left); i <= right; i++)
        {
            int setBits(0);
            int temp = i;
            while(temp)
            {
                setBits += (temp % 2);
                temp /= 2;
            }
            if(sieve[setBits])
            {
                res++;
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        int left = 6;
        int right = 10;
        int output = 4;
        assert(sol.countPrimeSetBits(left, right) == output);
    }
    {
        int left = 10;
        int right = 15;
        int output = 5;
        assert(sol.countPrimeSetBits(left, right) == output);
    }
    return 0;
}