#include <assert.h>
#include <iostream>

#include <vector>
#include <cmath>
#include <algorithm>

namespace KStep
{
    std::vector<long> getPrimes(long n)
    {
        std::vector<bool> sieve(n + 1, 0);
        std::vector<long> primes;
        for(long i(2); i <= n; i++)
        {
            if(sieve[i])continue;
            primes.push_back(i);
            for(long j(i * 2); j <= n; j += i)
            {
                sieve[j] = 1;
            }
        }
        return primes;
    }

    bool isKPrime(int k, long num, std::vector<long> primes)
    {
        int primeFactors(0);
        for(long prime: primes)
        {
            if(prime > num)break;
            while(num % prime == 0)
            {
                num /= prime;
                primeFactors ++;
            }
        }
        if(primeFactors == k)
            return true;
        return false;
    }
    
    std::vector<long> getKPrimes(int k, long m, long n)
    {
        std::vector<long> kprimes;
        std::vector<long> primes(getPrimes(n / 2));
        for(long i(m); i <= n; i++)
        {
            if(isKPrime(k, i, primes))
                kprimes.push_back(i);
        }
        return kprimes;
    }

    std::vector<std::pair <long, long>> kprimesStep(int k, int step, long long m, long long n)
    {
        std::vector<long> kprimes(getKPrimes(k, m, n));
        std::vector<std::pair<long, long>> res;

        for(size_t i(0); i < kprimes.size() - 1; i++)
        {
            if(find(kprimes.begin() + i + 1, kprimes.end(), kprimes[i] + step) != kprimes.end())
            {
                res.push_back(std::make_pair(kprimes[i], kprimes[i] + step));
            }
        }
        return res;
    }
}

void dotest(int k, int step, long long m, long long n, std::vector<std::pair <long, long>> sol)
{
    assert(KStep::kprimesStep(k, step, m, n) == sol);
}

int main()
{
    std::vector<std::pair <long, long>> sol = {};
    dotest(10, 8, 2425364, 2425700, sol);
    sol = {{2627408, 2627416}, {2627440, 2627448}, {2627496, 2627504}};
    dotest(6, 8, 2627371, 2627581, sol);
    
    return 0;
}