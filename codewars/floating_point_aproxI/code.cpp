#include <iostream>
#include <assert.h>

#include <cmath>
#include <iomanip>
#include <chrono>
#include <random>

namespace App
{
    double f(double x)
    {
      return x / (std::sqrt(1.0 + x) + 1.0);
    }
}

void assertFuzzyEquals(double act, double exp)
{
    bool inrange;
    double merr = 1e-12;
    if (exp == 0.0)
        inrange = std::abs(act) <= merr;
    else
    {
        double e = std::abs((act - exp) / exp);
        inrange = e <= merr;
    }
    if (inrange == false)
    {
        std::cout << std::setprecision(16);
        std::cout << "Expected should be near: " << exp << ", but got: " << act << std::endl;
    }
    assert(true == inrange);
}

void dotest(double x, double expected)
{
    assertFuzzyEquals(App::f(x), expected);
}

int main()
{
    dotest(2.6e-08, 1.29999999155e-08);
    dotest(1.4e-09, 6.999999997549999e-10);
    dotest(5.0e-06, 2.499996875007812e-06);
    dotest(2.4e-07, 1.1999999280000085e-07);
    return 0;
}
