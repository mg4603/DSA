#include <assert.h>
#include <iostream>

#include <string>
#include <cmath>
#include <sstream>
#include <iomanip>
#define M_PI 3.14159265358979323846

class PiApprox
{
    public: static std::string iterPi(double epsilon);
};

std::string PiApprox::iterPi(double epsilon){
    double pi_calc(0);
    int count(0);
    int sign(1);
    while(fabs(4 * pi_calc - M_PI) > epsilon){
        pi_calc += (sign * (1 / static_cast<double>((2 * count) + 1)));
        sign = - sign;
        count++;
    }
    std::stringstream ss;
    ss << '[' << count << ", " << std::fixed  << std::setprecision(10) << (4 * pi_calc) << ']';
    return ss.str();
}


int main()
{
    std::string sol1 = "[10, 3.0418396189]";
    std::string ans1 = PiApprox::iterPi(0.1);
    assert(ans1 == sol1);
}

