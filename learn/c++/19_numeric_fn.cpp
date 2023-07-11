#include <iostream>
#include <cmath>

int main()
{
    std::cout << "Numeric Functions " << std::endl << std::endl;
    // special values w.r.t floating point numbers:
    //      * nan: not a number
    //      * infinity
    //      * negative infinity
    // 
    std::cout << "Nan -> square root of a negative number: " <<
                sqrt(-5000) << std::endl;
    std::cout << "Nan: Keyword " << NAN << std::endl;
    std::cout << "-Nan: Keyword " << -NAN << std::endl << std::endl;

    std::cout << "Infinity: pow(9, 999) " << pow(9, 999) << std::endl;
    std::cout << "Infinity: keyword " << INFINITY << std::endl << std::endl;

    std::cout << "-Infinity: pow(-9, 999) " << pow(-9, 9999) << std::endl;
    std::cout << "-Infinity: keyword " << -INFINITY << std::endl << std::endl;

    // remainder function => can return a floating point value
    // modulo function always returns an int value
    std::cout << "remainder(10, 3): " << remainder(10, 3) << std::endl;
    std::cout << "10 % 3: " << 10 % 3 << std::endl;

    // std::cout << "10 % 3.25: " << 10 % 3.25 << std::endl; 
    // results in an compiler error
    std::cout << "remainder(10, 3.25): " << remainder(10, 3.25) << std::endl; 

    // fmax => returns the larger of the two arguments
    // fmin => returns the lesser of the two arguments
    // ceil => ceiling of floating point num
    // floor => floor of floating point num
    // trunc => truncate after decimal point
    // round => round floating point num to closest int
    
    return 0;
}