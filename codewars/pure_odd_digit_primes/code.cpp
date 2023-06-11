#include <iostream>
#include <assert.h>

#include <array>
#include <string>
#include <vector>

bool isOddDigitPrime(int n)
{
    while(n)
    {
        if(n % 2 == 0)
        {
            return false;
        }
        n /= 10;
    }
    return true;
}

std::vector<int> getPrimes(int n)
{
    std::vector<bool> sieve(n + 1, 0);
    std::vector<int> primes;

    for(int i(2); i < n + 1; i++)
    {
        if(sieve[i])continue;
        if(i != n && isOddDigitPrime(i))
        {
            primes.push_back(i);
        }
        for(int j(i * 2); j < n + 1; j+= i)
        {
            sieve[j] = 1;
        }
    }
    return primes;
}

bool isPrime(int n)
{
    if(n <= 1)return false;
    if(n <= 3)return true;
    if(n % 2 == 0 || n % 3 == 0)return false;

    for(int i(5); i * i <= n; i += 6)
    {
        if(n % i == 0 || n % (i + 2) == 0)
        {
            return false;
        }
    }
    return true;
}

int nextPrime(int n)
{
    if(n <= 1)return 2;
    int prime(n + 1);
    while(!isPrime(prime) || !isOddDigitPrime(prime))prime++;
    return prime;
}

std::array<int, 3> onlyOddDigitPrimes(const int n) {
    
    std::array<int, 3> res{0, 0, 0};
    if(n == 0)return res;

    int num(0);
    int bef(0);
    int aft(0);
    std::vector<int> primes = getPrimes(n);
    
    bef = primes.back();
    num = primes.size();
    aft = nextPrime(n);
    
    res[0] = num;
    res[1] = bef;
    res[2] = aft;
    return res;
}


int main()
{
    int n = 0;
    std::array<int, 3> arr = {};
    assert(onlyOddDigitPrimes(n) == arr);
    n = 20;
    arr = {7, 19, 31};
    assert(onlyOddDigitPrimes(n) == arr);
    n = 40;
    arr = {9, 37, 53};
    assert(onlyOddDigitPrimes(n) == arr);
    n = 55;
    arr = {10, 53, 59};
    assert(onlyOddDigitPrimes(n) == arr);
    n = 60;
    arr = {11, 59, 71};
    assert(onlyOddDigitPrimes(n) == arr);
    n = 100;
    arr = {15, 97, 113};
    assert(onlyOddDigitPrimes(n) == arr);
    return 0;
}