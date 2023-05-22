#include <iomanip>
#include <iostream>
#include <assert.h>

#include <cmath>

class ArcParabLen
{
public:
    static double lenCurve(int n);
};

double ArcParabLen::lenCurve(int n)
{
    double delta = 1 / static_cast<double>(n);
    double len(0);
    double x(0);
    for(int i(0); i < n; i++)
    {
        double nextX = x + delta;
        double y = x * x;
        double nextY = nextX * nextX;
        len += sqrt((nextY - y) * (nextY - y) + (nextX - x) * (nextX - x));
        x = nextX; 
    }
    return len;
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
void dotest(int nb, double expected)
{
    assertFuzzyEquals(ArcParabLen::lenCurve(nb), expected);
}

int main()
{
    dotest(1, 1.414213562);
    dotest(10, 1.478197397);
    return 0;
}