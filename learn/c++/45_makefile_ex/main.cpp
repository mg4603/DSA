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

    std::cout << "3 ^ 2: " << pow(3) << std::endl;
    std::cout << "3 ^ 3: " << pow(3, 3) << std::endl;
    std::cout << "area of square of side 10: " << area(10) << std::endl;
    std::cout << "area of rectangle of length 10 and width 20: " << 
                    area(10, 20) << std::endl;
}
