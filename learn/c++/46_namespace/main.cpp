#include <iostream>
// need to be included in the main file and implementation file
#include "math_utils.h"

// when compiling use the -c flag to create object files
// 
// executable files can be created by compiling the object files or source files
// 
// object files are used to distribute the library without distributing the 
// source code
// 
int main()
{
    std::cout << "Multi-File Compilation\n\n";

    // make calls to functions that are a part of the utilities namespace
    // by prefixing utilities:: to them
    std::cout << "3 ^ 2: " << utilities::pow(3) << std::endl;
    std::cout << "3 ^ 3: " << utilities::pow(3, 3) << std::endl;
    std::cout << "area of square of side 10: " << utilities::area(10) << std::endl;
    std::cout << "area of rectangle of length 10 and width 20: " << 
                    utilities::area(10, 20) << std::endl;
}
