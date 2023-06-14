#include <iostream>
#include <assert.h>

#include <string>
#include <cmath>
#include <vector>

bool isPrime(int n)
{
    if(n <= 1)return false;
    if(n <= 3)return true;
    if(n % 2 == 0 || n % 3 == 0)return false;

    for(int i(5); i < sqrt(n); i += 6)
    {
        if(n % i == 0 || n % (i + 2) == 0)return false;
    }
    return true;
}

unsigned int countSpecMult(const unsigned int n, const unsigned int mxval) {

    int div(2);
    int num(3);
    int primes(1);
    while(primes < n)
    {
        if(isPrime(num))
        {
            div *= num;
            primes++;
        }
        num += 2;
    }
    
    return mxval / div;
}

int main()
{
    unsigned int n = 2, mxval = 100;
    assert(countSpecMult(n, mxval) == 16);
    n = 2, mxval = 1000;
    assert(countSpecMult(n, mxval) == 166);
    n = 2, mxval = 10000;
    assert(countSpecMult(n, mxval) == 1666);
    n = 2, mxval = 100000;
    assert(countSpecMult(n, mxval) == 16666);
    n = 3, mxval = 100;
    assert(countSpecMult(n, mxval) == 3);
    n = 3, mxval = 1000;
    assert(countSpecMult(n, mxval) == 33);
    n = 3, mxval = 10000;
    assert(countSpecMult(n, mxval) == 333);
    n = 3, mxval = 100000;
    assert(countSpecMult(n, mxval) == 3333);
    n = 4, mxval = 100;
    assert(countSpecMult(n, mxval) == 0);
    n = 4, mxval = 1000;
    assert(countSpecMult(n, mxval) == 4);
    n = 4, mxval = 10000;
    assert(countSpecMult(n, mxval) == 47);
    n = 4, mxval = 100000;
    assert(countSpecMult(n, mxval) == 476);
    return 0;
}