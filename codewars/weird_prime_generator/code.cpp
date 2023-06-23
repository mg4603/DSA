#include <assert.h>
#include <iostream>

// 1. an(n) with param n: returns the first n terms of the series a(n)
// 2. gn(n) with param n: returns the first n terms of the series g(n)
// 3. countOnes(n) with param n: return the number of ones in the series gn(n)
// 4. p(n) with param n: return an array with the first n distinct primes in gn(n)
// 5. maxPn(n) with param n: return the largest prime in p(n)
// 6. anOver(n) with param n: return an array of a(i)/i for every i such that  
// g(i) != 1
// 7. anOverAverage(n) with param n: returns and integer(the avg of anOver(n))

#include <vector>
#include <set>
#include <algorithm>
#include <numeric>

class WeirdPrimeGen
{
    static long long gcd(long long a, long long b);
public:
    
    static std::vector<long long> an(long long n);
    static std::vector<long long> gn(long long n);
    static long long countOnes(long long n);
    static std::vector<long long> pn(long long n);
    static long long maxPn(long long n);
    static std::vector<double> anOver(long long n);
    static int anOverAverage(long long n);
};

long long WeirdPrimeGen::gcd(long long a, long long b)
{
    if(b == 0)
    {
        return a;
    }
    return gcd(b, a%b);
}

std::vector<long long> WeirdPrimeGen::an(long long n)
{
    std::vector<long long> res;
    res.push_back(7);
    for(int i(1); i < n; i++)
    {
        res.push_back(res.back() + gcd(i+1 , res.back()));
    }
    return res;
}

std::vector<long long> WeirdPrimeGen::gn(long long n)
{
    std::vector<long long> res(an(n));
    for(long long i(1); i < n; i++)
    {
        res[i] = res[i] - res[i-1];
    }
    res[0] = 1;
    return res;
}
long long WeirdPrimeGen::countOnes(long long n)
{
    std::vector<long long> res(an(n));
    long long cnt(1);
    for(long long i(1); i < n; i++)
    {
        if(res[i] - res[i - 1] == 1)
            cnt++;
    }
    return cnt;
}
std::vector<long long> WeirdPrimeGen::pn(long long n)
{
    std::vector<long long> res;
    std::set<long long> encounteredPrimes;
    long long prev(7);
    long long pos(2);
    while(res.size() != n)
    {
        long long cur(prev + gcd(pos, prev));
        long long temp(cur - prev);
        if(encounteredPrimes.find(temp) == encounteredPrimes.end() && temp != 1)
        {
            encounteredPrimes.insert(temp);
            res.push_back(temp);
        }
        prev = cur;
        pos++;
    }
    return res;
}
long long WeirdPrimeGen::maxPn(long long n)
{
    std::vector<long long> pseries(pn(n));
    return *std::max_element(pseries.begin(), pseries.end());
}
std::vector<double> WeirdPrimeGen::anOver(long long n)
{
    long long prev(7);
    long long pos(2);
    std::vector<double> res;
    while(res.size() != n)
    {
        long long cur(prev + gcd(pos, prev));
        if(cur - prev != 1)
        {
            res.push_back(cur/pos);
        }
        prev = cur;
        pos++;

    }
    return res;
}
int WeirdPrimeGen::anOverAverage(long long n)
{
    std::vector<double> anOverSeries(anOver(n));
    return std::accumulate(anOverSeries.begin(), anOverSeries.end(), 0) / n;
}


void testequal(long long ans, long long sol) {
    assert(ans == sol);
}

int main()
{
    std::cout << "Test countOnes\n";
    testequal(WeirdPrimeGen::countOnes(1), 1);
    testequal(WeirdPrimeGen::countOnes(10), 8);
    std::cout << "Test maxPn\n";
    testequal(WeirdPrimeGen::maxPn(1), 5);
    testequal(WeirdPrimeGen::maxPn(5), 47);
    std::cout << "Test anOverAverage\n";
    testequal(WeirdPrimeGen::anOverAverage(1), 3);
    return 0;
}
