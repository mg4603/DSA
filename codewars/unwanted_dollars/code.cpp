#include <assert.h>
#include <iostream>
#include <iomanip>

#include <cmath>
#include <string>
#include <algorithm>

double money_value(const std::string &s)
{
    double val(0.0);

    std::string new_s(s);
    new_s.erase(std::remove(new_s.begin(), new_s.end(), ' '), new_s.end());
    new_s.erase(std::remove(new_s.begin(), new_s.end(), '$'), new_s.end());
    new_s.erase(std::remove(new_s.begin(), new_s.end(), '-'), new_s.end());
    if(new_s.size() == 0)
    {
        return val;
    }
    for(char c: new_s)
    {
        if(!isdigit(c) && c != '-' && c != '.')
        {
            return val;
        }
    }
    
    val = std::stod(new_s);
    if(s.find('-') != std::string::npos){
        return -val;
    }
    return val;
}

double plusDelta(double val, double errorTolerance)
{
    return val + errorTolerance;
}

double minusDelta(double val, double errorTolerance)
{
    return val - errorTolerance;
}

int main()
{
 double error_tolerance = 1e-9;
 
    assert(money_value("12.34")    <= plusDelta(12.34,   error_tolerance) && money_value("12.34")     >= minusDelta(12.34,   error_tolerance));
    assert(money_value(" $5.67")   <= plusDelta(5.67,    error_tolerance) && money_value(" $5.67")    >= minusDelta(5.67,    error_tolerance));
    assert(money_value("-0.89")    <= plusDelta(-0.89,   error_tolerance) && money_value("-0.89")     >= minusDelta(-0.89,   error_tolerance));
    assert(money_value("-$ 0.1")   <= plusDelta(-0.10,   error_tolerance) && money_value("-$ 0.1")    >= minusDelta(-0.10,   error_tolerance));
    assert(money_value("$-2.3456") <= plusDelta(-2.3456, error_tolerance) && money_value("$-2.3456")  >= minusDelta(-2.3456, error_tolerance));
    assert(money_value("007")      <= plusDelta(7.00,    error_tolerance) && money_value("007")       >= minusDelta(7.00,    error_tolerance));
    assert(money_value(" $ 89")    <= plusDelta(89.0,    error_tolerance) && money_value(" $ 89")     >= minusDelta(89.0,    error_tolerance));
    assert(money_value("   .11")   <= plusDelta(0.11,    error_tolerance) && money_value("   .11")    >= minusDelta(0.11,    error_tolerance));
    assert(money_value("$.2")      <= plusDelta(0.20,    error_tolerance) && money_value("$.2")       >= minusDelta(0.20,    error_tolerance));
    assert(money_value("-.34")     <= plusDelta(-0.34,   error_tolerance) && money_value("-.34")      >= minusDelta(-0.34,   error_tolerance));
    assert(money_value("$$$")      <= plusDelta(0.0,     error_tolerance) && money_value("$$$")       >= minusDelta(0.0,     error_tolerance));
    return 0;
}
