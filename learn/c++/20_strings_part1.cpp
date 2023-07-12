#include <iostream>
#include <string>

int main()
{
    std::cout << "In Strings " << std::endl;

    // default value of a string is an empty string ""
    std::string greeting = "Hello";

    // strings behave like arrays of characters and characters can be selected
    // using their index in the string
    std::cout << "1st element of greeting: " << greeting[0] << 
                std::endl << std::endl;

    // + operator concatenates strings or a single character and a string
    std::cout << "Concatenate two strings: " +  greeting + " there" << std::endl;

    std::cout << "Concatenate a string and a char: " << greeting + '!' << 
                    std::endl << std::endl;

    // += operator can be used to append to a string
    greeting += " world!";
    std::cout << "Append to greeting: " << greeting << std::endl << std::endl;

    // method - functions tied to a class
    //      * called using dot operator with object of the class
    //      * member function:
    //          * part of the object
    //          * defined in the class
    // 
    // string methods:
    //      * length: returns length of string
    // 
    std::cout << "Length of greeting: " << greeting.length() << std::endl << std::endl;
    
    // c-style strings
    char name[] = "My name"; // an array of characters
    // can't reassign c-style strings
    // name = "name"; // results in a compile error
    std::cout << name << std::endl << std::endl;

    // user input
    // only captures input upto the first space
    // is user input is "My name", only "My" will be stored in the variable
    std::string user_input;
    std::cout << "Enter some input: " << std::endl;
    std::cin >> user_input; 
    std::cout << "User input was: " << user_input << std::endl;
    return 0;
}