#include <assert.h>
#include <iostream>

#include <vector>
#include <algorithm>

class Epidem
{
public:
    static int epidemic(int tm, int n, int s0, int i0, double b, double a);
};

int Epidem::epidemic(int tm, int n, int s0, int i0, double b, double a)
{
    double dt(tm/ static_cast<double>(n));
    std::vector<double> susceptible;
    std::vector<double> infected;
    std::vector<double> recovered;
    susceptible.push_back(s0);
    infected.push_back(i0);
    recovered.push_back(0);
    for(int i(0); i < n; i++)
    {
        susceptible.push_back(susceptible[i] - dt * b * susceptible[i] * infected[i]);
        infected.push_back(infected[i] + dt * (b * susceptible[i] * infected[i] - a * infected[i]));
        recovered.push_back(recovered[i] + dt * infected[i] * a);
    }
    return *std::max_element(infected.begin(), infected.end());
}

void testequal(int ans, int sol) {
    assert(ans == sol);
}
void dotest(int tm, int n, int s0, int i0, double b, double a, int expected)
{
    testequal(Epidem::epidemic(tm, n, s0, i0, b, a), expected);
}

int main()
{
    int tm = 18 ;int n = 432 ;int s0 = 1004 ;int i0 = 1 ;double b = 0.00209 ;double a = 0.51;
    dotest(tm, n, s0, i0, b, a, 420);
    tm = 12 ;n = 288 ;s0 = 1007 ;i0 = 2 ;b = 0.00206 ;a = 0.45;
    dotest(tm, n, s0, i0, b, a, 461);
    return 0;
}
