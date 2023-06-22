#include <assert.h>
#include <iostream>

#include <vector>

std::vector<int> getPrimes(int n)
{
    std::vector<bool> sieve(n + 1, 0);
    std::vector<int> primes;
    for(int i(2); i <= n; i++)
    {
        if(sieve[i])continue;
        primes.push_back(i);
        for(int j(2 * i); j <= n; j+=i)
        {
            sieve[j] = 1;
        }
    }
    return primes;
}

int solve(int a, int b){
    std::vector<int> primes = getPrimes(b);
    int n(0);
    std::cout << 1 << std::endl;
    while(primes[primes[n] - 1] < a)n++;
    int sum(0);
    while(primes.size() >= primes[n] && primes[primes[n] - 1] <= b)
    {
        sum += primes[primes[n] - 1];
        n++;
    }
    return sum;
}

int main()
{
    assert(solve(0,10) == 8);
    assert(solve(2,200) == 1080);
    assert(solve(1000,100000) == 52114889);
    assert(solve(4000,500000) == 972664400);
    return 0;
}