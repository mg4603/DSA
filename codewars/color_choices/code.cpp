#include <assert.h>
#include <iostream>


class ColorChoice
{
    private:
        static long long combination(long long n, long long x);
    public:
        static long long checkChoose(long long m, int n);
};

long long ColorChoice::combination(long long n, long long x)
{
    if(x > n)
    {
        return 0;
    }
    if(n - x < x)
    {
        x = n - x;
    }

    long long fact(1);
    for(long long i(1); i <= x; i++)
    {
        fact *= (n - i  + 1);
        fact /= i;
    }
    return fact;
}

long long ColorChoice::checkChoose(long long m, int n)
{
    if(m == 0 || n < 1)
    {
        return -1;
    }

    for(long long x(0); x < n; x++)
    {
        if(combination(n, x) == m)
        {
            return x;
        }
    }
    return -1;
}

void testequal(long long ans, long long sol) {
    assert(ans == sol);
}
void dotest(long long m, int n, long long expected)
{
    testequal(ColorChoice::checkChoose(m, n), expected);
}
int main()
{
    dotest(6, 4, 2);
    dotest(4, 4, 1);
    dotest(4, 2, -1);
    dotest(35, 7, 3);
    return 0;
}