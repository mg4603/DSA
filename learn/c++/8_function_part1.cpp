#include <iostream>
#include <cmath>

// main function is defined here - automatically called by the compiler
int main()
{
    // a function is called by using it's name followed by parentheses
    // passing arguments to the function:
    //      arguments to be used by the function are entered in between
    //      the parentheses
    // functions can return some value after operating on the input
    // 
    // the returned value can be used inside some other expression or output
    // to the console
    // 
    // eg: 
    //      pow is the function name
    //      10 and 2 are arguments passed to the function
    //      100 is the output
    std::cout << "In function part1" << std::endl;
    std::cout << std::pow(10, 2) << std::endl;;
    return 0;
}