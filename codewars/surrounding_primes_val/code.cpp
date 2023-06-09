#include <assert.h>
#include <iostream>

#include <array>
#include <string>
#include <vector>

std::array<unsigned int, 2> primeBefAft(const unsigned int num) {

    std::vector<bool> sieve(num + (num / 2), 0);
    std::vector<unsigned int> primes;
    for(unsigned int i(2); i < num + (num / 2); i++)
    {
        if(sieve[i])continue;
        primes.push_back(i);
        for(unsigned int j(i * 2); j < num + (num / 2); j += i)
        {
            sieve[j] = 1;
        }
    }

    size_t pos(0);
    while(primes[pos++] < num);

    std::array<unsigned int, 2> res;

    if(primes[pos - 1] == num)
    {
        res[0] = primes[pos - 2];
        res[1] = primes[pos];
        return res;
    }
    
    res[0] = primes[pos - 2];
    res[1] = primes[pos - 1];
    return res;
}


int main()
{
    unsigned int num = 100;
    std::array<unsigned int, 2> arr = {97, 101};
    std::cout<<1<<std::endl;
    assert(primeBefAft(num) == arr);
    num = 97;
    arr = {89, 101};
    assert(primeBefAft(num) == arr);
    num = 101;
    arr = {97, 103};
    assert(primeBefAft(num) == arr);
    num = 120;
    arr = {113, 127};
    assert(primeBefAft(num) == arr);
    num = 130;
    arr = {127, 131};
    assert(primeBefAft(num) == arr);
    num = 500;
    arr = {499, 503};
    assert(primeBefAft(num) == arr);
    num = 10004266;
    arr = {10004263, 10004273};
    assert(primeBefAft(num) == arr);
    return 0;
}