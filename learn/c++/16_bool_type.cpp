#include <iostream>

int main()
{
    std::cout << "In bool type " << std::endl;
    // bool - boolean - true or false
    // zero is false
    // all other values are true
    // 
    // true is represented by 1
    // false is represented by 0
    // 
    // can be used as a flag -> to indicate is some event happened
    // 
    // manipulators can be used to output true or false:
    //      * boolalpha ==> any attempt to output a bool after using
    //                      boolalpha will be output as true or false
    //      * endl is an example of a manipulator
    bool pizza_is_good = '0';
    std::cout << "char 0: " << std::boolalpha <<pizza_is_good << std::endl;

    pizza_is_good = 1;
    std::cout << "int 1: " << pizza_is_good << std::endl;

    pizza_is_good = -1;
    std::cout << "int -1: " << pizza_is_good << std::endl;

    pizza_is_good = true;
    std::cout << "keyword true: " << pizza_is_good << std::endl;

    pizza_is_good = 0;
    std::cout << "int 0: " << pizza_is_good << std::endl;

    return 0;
}