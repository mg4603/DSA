#include <assert.h>
#include <iostream>

#include <utility>
#include <vector>
#define ll long long

class StepInPrimes
{
public:
    static std::pair <ll, ll> step(int g, ll m, ll n);
};

std::pair<ll, ll> StepInPrimes::step(int g, ll m, ll n)
{
    std::vector<ll> sieve(n + 1, 0);
    for(size_t i(2); i < n + 1; i++){
        for(size_t j(2 * i); j < n + 1; j += i){
            sieve[j] = 1;
        }
    }

    
    for(size_t i(m); i < n - g; i++){
        if(!sieve[i] && !sieve[i + g]){
            return std::make_pair(i, i + g);
        }
    }

    return std::make_pair(0, 0);
}

void testequal(std::pair <long long, long long> ans, std::pair <long long, long long> sol) {
    assert(ans == sol);
}
void dotest(int g, long long m, long long n, std::pair <long long, long long> expected)
{
    testequal(StepInPrimes::step(g, m, n), expected);
}

int main()
{
    dotest(2,100,110, {101, 103});
    dotest(11,30000,100000, {0, 0});
    dotest(2,2,50, {3, 5});
    dotest(4,100,110, {103, 107});
    dotest(6,100,110, {101, 107});
    dotest(8,300,400, {359, 367});
    dotest(10,300,400, {307, 317});
    return 0;
}