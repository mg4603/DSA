#include <iostream>
#include <assert.h>

#include <string>
#include <vector>
#include <numeric>

std::vector<size_t> sieve(size_t n)
{
    std::vector<bool> sieveOfEratosthenes(n + 1, 0);
    std::vector<size_t> primes;

    for(size_t i(2); i < n; i++)
    {
        if(sieveOfEratosthenes[i] == 0)
        {
            primes.push_back(i);
            for(size_t j(2 * i); j < n; j += i)
            {
                sieveOfEratosthenes[j] = 1;
            }
        }
    }
    return primes;
}

int solve(std::vector<int> v)
{
    std::vector<size_t> primes = sieve(v.size());
    int sum(std::accumulate(primes.begin(), primes.end(), 0, [v](int a, size_t b){
        return a + v[b];
    }));
    return sum;
}

int main()
{
    assert(solve(std::vector<int>{}) == 0);
    assert(solve(std::vector<int>{1,2,3,4}) == 7);
    assert(solve(std::vector<int>{1,2,3,4,5,6}) == 13);
    assert(solve(std::vector<int>{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15}) == 47);
    return 0;
}