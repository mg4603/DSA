#include <assert.h>
#include <iostream>

#include <vector>
#define ull unsigned long long
#define usi unsigned short int

ull numPrimorial(usi n){
    ull prod(2);
    std::vector<ull> primes;
    primes.push_back(2);
    ull i(2);
    while(primes.size() < n){
        bool isPrime = true;
        for(ull prime: primes){
            if (i % prime == 0){
                isPrime = false;
            }
        }
        if(isPrime){
            primes.push_back(i);
            prod *= i;
        }
        i++;
    }
    return prod;
}

int main(){
    assert(numPrimorial (3) == 30);
    assert(numPrimorial (4) == 210);
    assert(numPrimorial (5) == 2310);
    assert(numPrimorial (8) == 9699690);
    assert(numPrimorial (9) == 223092870);
    return 0;
}