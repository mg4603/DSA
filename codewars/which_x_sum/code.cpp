#include <iostream>
#include <assert.h>

#include <cmath>
#include <iomanip>

double solve(double m)
{
    double det (std::sqrt(4 * m + 1));
    double x1 ((2 * m + 1 - det) / (2 * m));
    double x2 ((2 * m + 1 + det) / ( 2 * m));
    return x1;
}

void assertFuzzy(double m, double expect)
{
    std::cout << std::setprecision(12);
    std::cout << std::scientific;
    double merr = 1e-12;
    std::cout << "Testing: " << m <<std::endl;
    double actual = solve(m);
    std::cout << "Actual: " << actual << std::endl;
    std::cout << "Expect: " << expect << std::endl << std::endl;
    bool inrange = std::abs(actual - expect) <= merr;
    if (inrange == false)
        std::cout << "Expected: " << expect << ", and got " << actual << std::endl;
    assert(true == inrange);
}

void tests()
{
    assertFuzzy(2.00, 5.000000000000e-01);
    assertFuzzy(4.00, 6.096117967978e-01);
    assertFuzzy(5.00, 6.417424305044e-01);
}

int main()
{
    tests();
    return 0;
}