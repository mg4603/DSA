#include <iostream>
// macros
// c-style definition of constants
// generic style guide: all caps
#define X1 10

int main()
{
    std::cout << "In constants " << std::endl;
    // Constants:
    //      * literal constants: literals are considered constants
    //      * symbolic constants: variables prefixed with const
    //          * read-only after declaration
    //          * if not initialized during declaration, it can't be initialized
    //            later on.  
    //          * create a constant and use it throughout the code without 
    //            having to worry about value being changed
    //      * enum constants
    //      * macros: c-style definition of constants
    
    5; // literal constant
    
    // generic style guide: capitalize the first letter of constant identifier
    const int X = 5; // symbolic constant
    std::cout << "Symbolic constant: " << X << std::endl;
    // X = 10;   // can't be done ===> results in compile error

    enum { y = 100 };
    //  y = 20;  // can't be done ==> results in compile error
    std::cout << "Enum Constant " << y << std::endl;
    
    return 0;
}