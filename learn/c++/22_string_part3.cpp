#include <iostream>

int main()
{
    std::cout << "String Part 3: string modifier methods" << std::endl;
    // string methods
    //      * length   : length of string
    //      * size     : same purpose as length (all stl classes have a 
    //                   size method by default)
    //      * append   : append specified string to the string object calling 
    //                   append (can also use the += operator)
    //      * insert   : insert a string at specified index
    //      * erase    : erase the specified number of characters starting from 
    //                   specified index, or all characters after the specified
    //                   index if no number of characters is specified.
    //      * pop_back : remove the last character of a string
    //      * replace  : replace a specified number of characters starting at 
    //                   the specified index with a different string
    std::string greeting("Hello");
    std::cout << "Length of greeting: " << greeting.length() << std::endl;
    std::cout << "Length of greeting (using size): " << greeting.size() << 
                    std::endl << std::endl;

    std::cout << "Greeting: " << greeting << std::endl;
    greeting.append(" World!");
    std::cout << "Append World! to greeting: " << greeting << std::endl << 
                std::endl;

    std::cout << "greeting: " << greeting << std::endl;
    greeting.insert(3, "     ");
    std::cout << "Insert \"     \" at the 3rd index: " << greeting << 
                std::endl << std::endl;
    
    std::cout << "greeting: " << greeting << std::endl;
    greeting.erase(3, 5);
    std::cout << "Erase 5 characters starting at the 3rd index: " << greeting <<
                std::endl << std::endl;

    std::cout << "greeting: " << greeting << std::endl;
    greeting.pop_back();
    std::cout << "Remove the \"!\" from greeting: " << greeting << std::endl <<
                std::endl;

    std::cout << "greeting: " << greeting << std::endl;
    greeting.replace(0, 5, "Good bye,");
    std::cout << "Replace \"Hello\" in greeting with \"Good bye,\": " << greeting <<
                std::endl << std::endl;
    return 0;
}