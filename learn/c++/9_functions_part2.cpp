#include <iostream>
// Create custom functions
//      * makes code more scalable
//      * reusable blocks of code
// 
// During the function definition, inputs are defined as parameters
// arguments during function calls get stored in parameters


// multiply takes two arguments that are stored in parameters
// a and b of type int and returns value a * b of type int

// function declaration
//      * declare but not define function
//      * is a requirement
//      * function defintion can also serve as a declaration
//      * has to happen before function is called
//      * goes into header files

// function definition
//      * put in separate files for object code.
int multiply(int a, int b)
{
    return a * b;
}

int main()
{
    int x = 5;
    // calling function
    x = multiply(x, 2);
    std::cout << "In Functions part 2" << std::endl;
    std::cout << "Computed with fn multiply: " << x << std::endl;
    return 0;
}