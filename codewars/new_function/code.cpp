#include <iostream>
#include <assert.h>

#include <cstdint>
#include <cmath>
#include <vector>
#include <map>

uint64_t sod(uint64_t n)
{
    uint64_t sum(0);
    for(uint64_t i(2); i <= sqrt(n); i++)
    {
        if(n % i == 0)
        {
            sum += i;
            if(n / i != i)
            {
                sum += (n / i);
            }
        }
    }
    return sum;
}

uint64_t newFunction(const uint64_t n){
    uint64_t csod(0);
    
    uint64_t k(sqrt(n));
    for(uint64_t i(2); i <= k; i++)
    {
        csod += (i * ((n / i) - 1));
        uint64_t j(n / i);
        csod += ((j * (j + 1) / 2) - (k * (k + 1) / 2));
    }
    return csod;
}

void dotest(int64_t actual, int64_t expected){
    assert(actual == expected);
}

int main()
{
    assert(newFunction(12) == 38);
    assert(newFunction(24) == 168);
}
