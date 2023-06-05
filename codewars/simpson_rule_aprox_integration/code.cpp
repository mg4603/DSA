#include <assert.h>
#include <iostream>

#include <iomanip>

#include <cmath>

#define pi 3.14159265359
class SimpsonIntegration
{
private:
  static double f(double x);
public:
    static double simpson(int n);
};

double SimpsonIntegration::f(double x)
{
  return (3/2.0) * std::pow(std::sin(x), 3);
}

double SimpsonIntegration::simpson(int n)
{
  double term1(0);
  double term2(0);
  double h(pi / n);
  for(int i(1); i <= n/2; i++)
  {
    term1 += f((2 * i - 1) * h);
    if(i != n/2)
      term2 += f(2 * i * h);
  }
  return (pi / (3 * n)) * (f(0) + f(pi) + 4 * term1 + 2 * term2);
}

void assertFuzzyEquals(double act, double exp)
{
    bool inrange = std::abs(act - exp) <= 1e-10;
    if (inrange == false)
    {
        std::cout << std::setprecision(10);
        std::cout << "At 1e-10: Expected should be " << exp << ", but got " << act << std::endl;
    }
    assert(true == inrange);
}
void dotest(int n, double expected)
{
    assertFuzzyEquals(SimpsonIntegration::simpson(n), expected);
}

int main()
{
    dotest(290, 1.9999999986);
    dotest(72, 1.9999996367);
    dotest(252, 1.9999999975);
    dotest(40, 1.9999961668);
    return 0;
}
