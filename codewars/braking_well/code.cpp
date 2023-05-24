#include <iostream>
#include <assert.h>

#include <iomanip>
#include <cmath>

class Braking
{
public:
    static double dist(double v, double mu);
    static double speed(double d, double mu);
};

double Braking::dist(double v, double mu)
{
    return (v * (5 / 18.0)) + (v * v * (5 / 18.0) * (5 / 18.0)) / ( 2 * mu * 9.81) ;
}

double Braking::speed(double d, double mu)
{
    double g = 9.81;
    return (sqrt((mu * mu) * (g * g) + (2 * mu * g * d)) - (mu * g)) * (18 / 5.0);
}

void assertFuzzyEquals(double act, double exp)
{
    bool inrange = std::abs(act - exp) <= 1e-6;
    if (inrange == false)
    {
        std::cout << std::setprecision(6);
        std::cout << "At 1e-6: Expected should be " << exp << ", but got " << act << std::endl;
    }
    assert(true == inrange);
}
static void dotest1(double v, double mu, double expected)
{
    assertFuzzyEquals(Braking::dist(v, mu), expected);
}
static void dotest2(double d, double mu, double expected)
{
    assertFuzzyEquals(Braking::speed(d, mu), expected);
}

void distTests()
{
    dotest1(100, 0.7, 83.9598760937531);
    dotest1(144, 0.3, 311.83146449201496);
    dotest1(92, 0.5, 92.12909477605366);
}
void speedTests()
{
    dotest2(159, 0.8, 153.79671564846308);
    dotest2(164, 0.7, 147.91115701756493);
}

int main()
{
    distTests();
    speedTests();
}