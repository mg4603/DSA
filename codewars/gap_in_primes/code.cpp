#include <utility>
#include <assert.h>
#include <vector>
#include <iostream>
#define ll long long

class GapInPrimes
{
public:
    static std::vector<ll> sieveOfEratosthenes(ll n){
        std::vector<ll> primes = std::vector<ll>();
        std::vector<ll> sieve = std::vector<ll>(n + 1, 0);
        for(ll i(2); i <= n; i ++){
            if(sieve[i] == 0){
                primes.push_back(i);
                for(ll j(i * i); j <= n; j += i){
                    sieve[j] = 1;
                }
            }
        }
        return primes;
    }

    static std::pair<long long, long long> gap(int g, long long m, long long n) {
        std::vector<ll> primes = sieveOfEratosthenes(n);
        for(size_t i(0); i < primes.size() - 1; i++){
            if(primes.at(i) > m){
                if(primes.at(i + 1) - primes.at(i) == g){
                    return {primes.at(i), primes.at(i + 1)};
                }
            }
        }
        return {0, 0};
  }
};





void testequal(std::pair <long long, long long> ans, std::pair <long long, long long> sol) {
    assert(ans == sol);
}
void dotest(int g, long long m, long long n, std::pair <long long, long long> expected)
{
    testequal(GapInPrimes::gap(g, m, n), expected);
}

int main(){
      dotest(2,100,110, {101, 103});
      dotest(4,100,110, {103, 107});
      dotest(6,100,110, {0, 0});
      dotest(8,300,400, {359, 367});
      dotest(10,300,400, {337, 347});
    
}
