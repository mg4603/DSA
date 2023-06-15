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

int cycle(int n) {
    if(gcd(10, n) != 1)
    {
        return -1;
    }

    std::string s;
    int rem(1);
    int len(1);

    while(true)
    {
        rem = (10 * rem) % n;
        s += std::to_string(rem);
        if(rem + '0' == s[0])
        {
            return len;
        }
        len++;
    }

    return 0;
}

static void dotest(int n, int expected) {
    int ans = cycle(n);
    std::cout << "Expected: " << expected << " Got: " << ans << std::endl;
    assert(ans == expected);
}

int main()
{
    dotest(33, 2);
    dotest(18118, -1);
    dotest(69, 22);
    dotest(197, 98);
    dotest(65, -1);
    return 0;
}