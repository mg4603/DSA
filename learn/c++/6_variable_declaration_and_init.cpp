#include <iostream>

int main()
{
    // variable
    //      * a container to store some value in
    //      * a variable name is called an identifier
    //      * it's type needs to be defined beforehand
    //      * eg: int
    // 
    // variable declaration
    //      * says that the identifier exists
    int slices; 
    
    // "=" -> assignment operator
    //        store value in a variable
    
    // variable initialization
    //      * assigns a value to the identifier
    //      * value assigned can be:
    //          * a literal (eg: 5)
    //          * an expression (eg: 5 + 1)
    //          * from another variable (eg: children = slices)
    //              * where children is another variable
    slices = 6;
    int children(slices);
    slices = 100;
    std::cout << "Variable declaration and initialization\n";
    std::cout << "Children: " << children << std::endl;
    std::cout << "Slices: " << slices << std::endl;
    return 0;
}