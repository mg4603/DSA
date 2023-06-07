#include <assert.h>
#include <iostream>

#include <vector>
#include <cmath>
#define ll long long

class PrimeConsec
{
private:
    static std::vector<ll> getPrimes(ll n);
    static int countPrimeDiv(ll n);
public:
    static int consecKprimes(int k, std::vector<ll> &arr);
};

std::vector<ll> PrimeConsec::getPrimes(ll n)
{
    std::vector<bool> sieve(n+1, 0);
    std::vector<ll> primes;
    for(long long i(2); i < n+1; i++)
    {
        if(sieve[i])continue;
        primes.push_back(i);
        for(long long j(i); j < n + 1; j+=i)
        {
            sieve[j] = 1;
        }
    }
    return primes;
}

int PrimeConsec::countPrimeDiv(ll n)
{
    std::vector<ll> primes = getPrimes(n/2);
    int cnt(0);
    for(auto prime: primes)
    {
        while(n % prime == 0)
        {
            n /= prime;
            cnt++;
        }
    }
    return cnt;
}

int PrimeConsec::consecKprimes(int k, std::vector<ll> &arr)
{
    for(ll &num: arr)
    {
        num = countPrimeDiv(num);
    }

    int cnt(0);
    for(int i(1); i < arr.size(); i++)
    {
        if(arr[i] == k && arr[i - 1] == k)
        {
            cnt++;
        }
    }
    return cnt;
}

void testequal(int ans, int sol)
{
    assert(ans == sol);
}
void dotest(int k, std::vector<long long> &arr, int expected)
{
    testequal(PrimeConsec::consecKprimes(k, arr), expected);
}

int main()
{
    std::vector<long long> a = {10081, 10071, 10077, 10065, 10060, 10070, 10086, 10083, 10078, 10076, 10089, 10085, 10063, 10074, 10068, 10073, 10072, 10075};
    dotest(2, a, 2);
    a =  {10064};
    dotest(6, a, 0);
    a = {10054, 10039, 10053, 10051, 10047, 10043, 10037, 10034};
    dotest(1, a, 0);
    a = {10158, 10182, 10184, 10172, 10179, 10168, 10156, 10165, 10155, 10161, 10178, 10170};
    dotest(3, a, 5);
    a = {10110, 10102, 10097, 10113, 10123, 10109, 10118, 10119, 10117, 10115, 10101, 10121, 10122};
    dotest(2, a, 7);
    return 0;
}
