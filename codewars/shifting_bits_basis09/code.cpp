#include <iostream>
#include <assert.h>

#include <cmath>

int nextLower(int n)
{
    if(n == 0)
    {
      return -1;
    }
    if(n == 1)
    {
      return 0;
    }
    bool neg(n < 0?true: false);

    n = std::abs(n);

    int pow2(0);

    if(neg)
    {
        pow2 = std::floor(std::log(n) / std::log(2));
        n = 1 << ++pow2;
        n = -n;
    }
    else
    {
        pow2 = std::ceil(std::log(n) / std::log(2));
        n = 1 << --pow2;
    }
    return n;
}

int main()
{
    assert(nextLower(4) == 2);
    assert(nextLower(-3) == -4);
    assert(nextLower(18) == 16);
    assert(nextLower(-16) == -32);
}