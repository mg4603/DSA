#include <assert.h>
#include <iostream>

#include <vector>
#include <cmath>
#define ll long long

class KPrimes
{
  public:
    static std::vector<long long> countKprimes(int k, long long start, long long end);
    static int puzzle(int s);
};

std::vector<size_t> sieve(size_t n)
{
    std::vector<bool> sieve(n + 1, 0);
    std::vector<size_t> primes;
    for(size_t i(2); i < n + 1; i++)
    {
        if(sieve[i] == 0)
        {   
            primes.push_back(i);
            for(size_t j(2 * i); j < n + 1; j += i){
                sieve[j] = 1;                
            }
        }
    }
    return primes;
}

std::vector<long long> KPrimes::countKprimes(int k, ll start, ll end)
{
    std::vector<size_t> primes = sieve(sqrt(end));
    std::vector<ll> res;
    for(ll i(start); i < end + 1; i++){
        int count(0);
        int idx(0);
        ll temp(i);
        while(temp > 1 && idx < primes.size())
        {
            if(temp % primes[idx] == 0){
                temp /= primes[idx];
                count++;
            }
            else{
                idx++;
            }
        }
        if(temp > 1){
            count++;
        }
        if(count == k){
            res.push_back(i);
        }
    }
    return res;
}

int KPrimes::puzzle(int s)
{
    std::vector<ll> aSet = countKprimes(1, 0, s);
    std::vector<ll> bSet = countKprimes(3, 0, s);
    std::vector<ll> cSet = countKprimes(7, 0, s);
    int count(0);
    for(size_t i(0); i < aSet.size(); i++)
    {
        for(size_t j(0); j < bSet.size(); j++)
        {
            for(size_t k(0); k < cSet.size(); k++)
            {
                if(aSet[i] + bSet[j] + cSet[k] == s)
                {
                    count++;
                }
            }
        }
    }
    return count;
}

void testequal(std::vector<long long> ans, std::vector<long long> sol)
{
    assert(ans == sol);
}
void testequalInt(int ans, int sol)
{
    assert(ans == sol);
}
void dotest(int k, long long start, long long nd, std::vector<long long> expected)
{
    testequal(KPrimes::countKprimes(k, start, nd), expected);
}

void tests_countKprimes()
{
    std::vector<long long> sol = {4,6,9,10,14,15,21,22,25,26,33,34,35,38,39,46,49,51,55,57,58,62,65,69,74,77,82,85,86,87,91,93,94,95};
    dotest(2, 0, 100, sol);
    sol =  {8, 12, 18, 20, 27, 28, 30, 42, 44, 45, 50, 52, 63, 66, 68, 70, 75, 76, 78, 92, 98, 99};
    dotest(3, 0, 100, sol);
}
void tests_puzzle()
{
    testequalInt(KPrimes::puzzle(138), 1);
    testequalInt(KPrimes::puzzle(143), 2);
    testequalInt(KPrimes::puzzle(250), 7);
}

int main()
{
    tests_countKprimes();
    tests_puzzle();
}