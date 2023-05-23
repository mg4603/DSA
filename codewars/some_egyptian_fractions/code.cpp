#include <iostream>
#include <assert.h>

#include <string>

class Decomp
{
private:
    static std::string egyptianFractions(long n, long d);
public:
  static std::string decompose(const std::string &nrStr, const std::string &drStr);
};

std::string Decomp::egyptianFractions(long n, long d)
{
    if(n == 0 || d == 0)
    return "";

    if(d % n == 0)
    {
        return ", 1/" + std::to_string(d / n);
    }
    if(n % d == 0)
    {
        return ", " + std::to_string(n / d);
    }
    if(n > d)
    {
        return ", " + std::to_string(n /d ) + egyptianFractions(n % d, d);
    }
    long x = d/n + 1;
    return ", 1/" + std::to_string(x) + egyptianFractions(n * x - d, d * x); // n/d - 1/x
}

std::string Decomp::decompose(const std::string &nrStr, const std::string &drStr)
{
    std::string res(egyptianFractions(stol(nrStr), stol(drStr)));
    if(res[0] == ',')
    {
        res = res.substr(2);
    }
    
    return "[" + res + "]";
}

void testequal(std::string ans, std::string sol) {
    assert(ans == sol);
}

int main()
{
    testequal(Decomp::decompose("3", "4"), "[1/2, 1/4]");
    testequal(Decomp::decompose("4", "5"), "[1/2, 1/4, 1/20]");
    testequal(Decomp::decompose("12", "4"), "[3]");
    testequal(Decomp::decompose("66", "100"), "[1/2, 1/7, 1/59, 1/5163, 1/53307975]");
    return 0;
}