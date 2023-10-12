#include <iostream>
#include <assert.h>

#include <vector>

const long long MOD = 1e9 + 7;
class Solution {
    long long fact(int n)
    {
        long long res = 1;
        for(int i = 1; i <= n; i++)
        {
            res *= i;
            res %= MOD;
        }
        return res;
    }
public:
    int numPrimeArrangements(int n) {
        std::vector<int> sieve(101, 1);
        sieve[0] = sieve[1] = 0;
        for(int i = 2; i <= 100; i++)
        {
            if(sieve[i])
            {   
                for(int j = i * i; j <= 100; j += i)
                {
                    sieve[j] = 0;
                }
            }
        }

        for(int i = 2; i <= 100; i++)
        {
            sieve[i] += sieve[i - 1];
        }
        return (fact(sieve[n]) * fact(n - sieve[n])) % MOD;
        
    }
};

int main()
{
    Solution sol;
    {
        int n = 5;
        int res = 12;
        assert(sol.numPrimeArrangements(n) == res);
    }
    {
        int n = 100;
        int res = 682289015;
        assert(sol.numPrimeArrangements(n) == res);
    }
    return 0;
}