#include <assert.h>
#include <iostream>

#include <string>
#include <cmath>
#include <set>

unsigned int getNumDivisors(unsigned int num)
{
    unsigned  div(1);
    std::set<unsigned int> divisors;
    while(div <= sqrt(num))
    {
        if(num % div == 0)
        {
            divisors.insert(div);
            divisors.insert(num / div);
        }
        div++;
    }
    return divisors.size();
}

unsigned int countDivisors(const unsigned int diff, const unsigned int nMax) {
    unsigned int cnt(0);
    for(unsigned int i(1); i < nMax; i++)
    {
        if(i + diff >= nMax)break;
        if(nMax && getNumDivisors(i) == getNumDivisors(i + diff))
        {
            cnt++;
        }
    }
    return cnt;
}

int main()
{
    unsigned int diff = 1, nMax = 50;
    assert(countDivisors(diff, nMax)  == 8);
    diff = 3,  nMax = 100;
    assert(countDivisors(diff, nMax)  == 7);
    diff = 3,  nMax = 200;
    assert(countDivisors(diff, nMax)  == 18);
    diff = 6,  nMax = 350;
    assert(countDivisors(diff, nMax)  == 86);
    diff = 6,  nMax = 1000;
    assert(countDivisors(diff, nMax)  == 214);
    diff = 7,  nMax = 1500;
    assert(countDivisors(diff, nMax)  == 189);
    diff = 7,  nMax = 2500;
    assert(countDivisors(diff, nMax)  == 309);
    diff = 7,  nMax = 3000;
    assert(countDivisors(diff, nMax)  == 366);
    diff = 9,  nMax = 4000;
    assert(countDivisors(diff, nMax)  == 487);
    diff = 9,  nMax = 5000;
    assert(countDivisors(diff, nMax)  == 622);
    diff = 11, nMax = 5000;
    assert(countDivisors(diff, nMax)  == 567);
}