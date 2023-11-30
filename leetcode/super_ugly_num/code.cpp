#include <iostream>
#include <assert.h>

#include <vector>
#include <limits>

class Solution {
public:
    int nthSuperUglyNumber(int n, std::vector<int>& primes) 
    {
        int primes_size = primes.size();
        std::vector<int> indices(primes_size, 0);

        std::vector<long long> ugly_nums(n, 0);
        ugly_nums[0] = 1;

        for(int i = 1; i < n; i++)
        {
            long long temp = std::numeric_limits<long long>::max();
            int pos = -1;
            for(int j = 0; j < primes_size; j++)
            {
                if(ugly_nums[indices[j]] * primes[j] < temp)
                {
                    temp = ugly_nums[indices[j]] * primes[j];
                    pos = j;
                }
            }

            for(int j = 0; j < primes_size; j++)
            {
                if(temp % primes[j] == 0)
                {
                    indices[j]++;
                }
            }
            ugly_nums[i] = temp;
        }

        return ugly_nums[n-1];
    }
};

int main()
{
    Solution sol;
    {
        int n = 12;
        std::vector<int> primes = {2,7,13,19};
        int res = 32;
        assert(sol.nthSuperUglyNumber(n, primes) == res);
    }
    {
        int n = 1;
        std::vector<int> primes = {2,3,5};
        int res = 1;
        assert(sol.nthSuperUglyNumber(n, primes) == res);
    }
    return 0;
}