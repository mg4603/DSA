#include <iostream>

int main()
{
    // escape sequences get interpreted rather than printed
    //      * \t - interpret a tab character
    //      * \n - interpret a newline character
    //      * \b - interpret a backspace
    //      * \v - interpret a vertical tab
    //      * \0 - null terminating character - terminate cstyle string
    //      * \" - interpret a double quote
    //      * \' - interpret a single quote
    //      * \\ - single backslash is seen as the start of escape sequence
    //              double backslash is used to insert backslash into a string
    // 
    std::cout << "In escape sequences: " << std::endl;
    std::cout << "New\nline" << std::endl;
    std::cout << "Tab\tcharacter" << std::endl;
    std::cout << "Backspace\bCharacter" << std::endl;
    std::cout << "Vertical\vtab" << std::endl;
    std::cout << "Null terminating \0character" << std::endl;
    std::cout << "\"Quotes\"" << std::endl;
    char single_quote = '\'';
    std::cout << single_quote << "Single quote" << single_quote << std::endl;
    std::cout << "Backslash \\ character" << std::endl;
    return 0;
}