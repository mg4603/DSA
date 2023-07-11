#include <iostream>
#include <float.h>

int main()
{
    std::cout << "In Floating Point Numbers" << std::endl;
    // Types of floating point datatypes
    //      * float - least trustworthy - least number of trustworthy 
    //              significant digits
    //      * double
    //      * long double
    // 
    //  Floating point numbers are stored in the form
    //          (77000 =stored as=> 7.7 * 10^4)
    //      * decimal point floated to the left or right with exponent 
    //  Only accurate upto a certain number of decimal places
    // 
    // 

    std::cout << "Float data type: ";
    float a = 10.0 / 3;
    a *= 1000000000;
    std::cout << std::fixed << a << std::endl;
    std::cout << "Float is trustworthy up to the " << FLT_DIG << 
                 "th significant digit." << std::endl << std::endl;

    double b = 77000; //7.7e4
    b = 7.7e4;
    b = 10.0 / 3;
    b *= 1000000000000000000;
    std::cout << "Double data type: " << b << std::endl;
    std::cout << "Double is trustworthy up to the " << DBL_DIG << 
                 "th significant digit." << std::endl << std::endl;

    long double c;
    std::cout << "Long double is trustworthy up to the " << LDBL_DIG << 
                 "th significant digit." << std::endl << std::endl;
    return 0;
}