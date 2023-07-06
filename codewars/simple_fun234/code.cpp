#include <iostream>
#include <assert.h>

int gcd(int a, int b)
{
    if(b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}

int eulersTotientFunction (int n){
    int cnt(1);

    for(int i(2); i < n; i++)
    {
        if(gcd(n, i) == 1)
        {
            cnt++;
        }
    }

    return cnt;
}

int main()
{
    assert(eulersTotientFunction(5) == 4);
    assert(eulersTotientFunction(49) == 42);
    assert(eulersTotientFunction(1) == 1);
    return 0;
}