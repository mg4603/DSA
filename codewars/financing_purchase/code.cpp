#include <assert.h>
#include <iostream>

#include <string>
#include <cmath>
#include <sstream>

std::string amort(double rate, int balance, int term, int numPayments)
{
    double bal = static_cast<double> (balance);
    double n = (bal * rate) / (100.0 * 12.0);
    double d = (1 - pow(1 + (rate / 100.0 / 12.0), -term));
    
    double c = n / d;
    double month_princ(0.0);

    for(int i(1); i <= numPayments; i++)
    {
        month_princ = c - (bal * rate / 100.0 / 12.0);
        bal -= month_princ;
    }

    std::stringstream ss;
    ss << "num_payment " << numPayments << " c " << round(c);
    ss << " princ " << round( month_princ) << " int ";
    ss << round(c - month_princ) << " balance " << round(bal);

    return ss.str();
}

void testequal(std::string ans, std::string sol) {
    assert(ans == sol);
}
void dotest(double rate, int balance, int term, int numPayments, std::string expect)
{
    testequal(amort(rate, balance, term, numPayments), expect);
}
void fixed()
{
    dotest(7.4, 10215, 24, 20, "num_payment 20 c 459 princ 445 int 14 balance 1809");
    dotest(7.4, 10215, 24, 20, "num_payment 20 c 459 princ 445 int 14 balance 1809");
    
}

int main()
{
    fixed();  
    return 0;
}