#include <assert.h>
#include <iostream>

#include <cmath>
typedef long long llg;

class Disguised2
{
    private:
        static long long comb(int n, int k);
    public:
        static long long v1(int n, int p);
        static long long u1(int n, int p);
        static long long v_eff(int n, int p);
        static long long u_eff(int n, int p);
};

long long Disguised2::comb(int n, int k)
{
    long long res(1);
    int d(2);
    for(int i(k + 1); i <= n; i++)
    {
        res *= i;
        if(res % d == 0 && d <= n - k)
        {
            res /= d;
            d++;
        }
    }
    return res;
}

long long Disguised2::v1(int n, int p)
{
    long long res(0);
    for(int i(0); i <= n; i++)
    {
        long long temp(pow(-1, i) * p * pow(4, n-i) * comb(2 * n -i, i));
        res += temp;
    }
    return res;
}

long long Disguised2::u1(int n, int p)
{
    long long res(0);
    for(int i(0); i <= n; i++)
    {
        long long temp(pow(-1, i) * p * pow(4, n-i) * comb(2 * n - i + 1, i));
        res += temp;
    }
    return res;
}

long long Disguised2::v_eff(int n, int p)
{
    return (2 * n  + 1) * p;
}

long long Disguised2::u_eff(int n, int p)
{
    return (n + 1) * p;
}



void testequal(llg ans, llg sol)
{
    assert(ans == sol);
}
static void dotest1(int n, int k, llg expected)
{
    testequal(Disguised2::v1(n, k), expected);
    testequal(Disguised2::v_eff(n, k), expected);
}
static void dotest2(int n, int k, llg expected) {
    testequal(Disguised2::u1(n, k), expected);
    testequal(Disguised2::u_eff(n, k), expected);
}
static void test1()
{
    dotest1(1, 12, 36);
    std::cout << "v1(1, 12)" << Disguised2::v1(1, 12) << std::endl;
    std::cout << "v1(2, 12)" << Disguised2::v1(2, 12) << std::endl;
    std::cout << "v1(3, 12)" << Disguised2::v1(3, 12) << std::endl;
    dotest1(2, 138, 690);
}
static void test2()
{
    dotest2(1, 14, 28);
    std::cout << "u1(1, 14)" << Disguised2::u1(1, 14) << std::endl;
    std::cout << "u1(2, 14)" << Disguised2::u1(2, 14) << std::endl;
    std::cout << "u1(3, 14)" << Disguised2::u1(3, 14) << std::endl;
    dotest2(4, 18, 90);
}

void fixed_Tests_1()
{
    std::cout << "u1" << std::endl;
    test1();
}
void fixed_Tests_2()
{
    std::cout << "v1" << std::endl;
    test2();
}

int main()
{
    fixed_Tests_1();
    fixed_Tests_2();
}