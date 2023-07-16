// need to be included in the main file and the implementation file
#include "math_utils.h"


double area(double length, double width)
{
    return length * width;
}

double area(double side)
{
    return area(side, side);
}

// default values for parameters are not included in the implementation file
double pow(double base, int exponent)
{
    double result = 1;
    for(int i(0); i < exponent; i++)
    {
        result *= base;
    }
    return result;
}