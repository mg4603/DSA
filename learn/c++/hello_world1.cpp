// preprocessor directive:
//      compiler puts the iostream file at the beginning of the program
#include <iostream> 

// return type(int)
//      type of the value being returned

int main() // main function
{
    // output to the console
    std::cout << "Hello world!\n";
    // preprocessor directive 
    //      #define EXIT_SUCCESS 0
    //      expands EXIT_SUCCESS to 0
    return EXIT_SUCCESS;
}