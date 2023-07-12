#include <iostream>

int main()
{
    std::cout << "Strings part 4: String operation methods" << std::endl;
    // string operation methods:
    //      * find            : given a string, find returns it's position in
    //                          in the string object or -1 if not found
    // 
    //      * substr          : given a position and length, it returns the
    //                          substring starting at specified position that is
    //                          of the specified length
    // 
    //      * find_first_of   : given a string, it returns the first position of
    //                          any member of that string in the string object.
    //                          or -1 if no member of the string is found
    // 
    //      * find_last_of    : given a string, it returns the last position of 
    //                          any member of that stirng in the string object
    //                          or -1 if no member of the string is found
    // 
    //      * compare         :  given a string, it returns 0 if the strings are same
    //                           1 if the given string is lexicographically larger and
    //                           -1 if the given string is lexicographically smaller
    // 
    //      * "==" operator   : check if both strings are the same
    // 
    // npos : 
    //      * is of type unsigned long
    //      * part of the std namespace
    //      * is equal to -1
    //      * is equal to max unsigned long value -1, due to overflow
    // 

    std::string greeting("Hello World!");

    std::cout << "greeting: " << greeting << std::endl;
    std::cout << "Position of \"World\" in greeting: " << 
                greeting.find("World") << std::endl;
    std::cout << "Position of \"Good bye,\" in greeting: " <<
                greeting.find("Good bye,") << std::endl << std::endl;
        
    std::cout << "greeting: " << greeting << std::endl;
    std::cout << "Substring of greeting starting at 0th index of length 5: " << 
                greeting.substr(0, 5) << std::endl << std::endl;

    std::cout << "greeting: " << greeting << std::endl;
    std::cout << "Position of first lower case vowel in greeting: " << 
                greeting.find_first_of("aeiou") << std::endl << std::endl;
    
    std::cout << "greeting: " << greeting << std::endl;
    std::cout << "Position of last lower case vowel in greeting: " <<
                greeting.find_last_of("aeiou") << std::endl << std::endl;
        
    
    std::cout << "greeting: " << greeting << std::boolalpha << std::endl;
    std::cout << "greeting == \"Hello World!\": " << (greeting == "Hello World!") <<
                std::endl << std::endl;
        
    std::cout << "greeting: " << greeting << std::boolalpha << std::endl;
    std::cout << "greeting.compare(\"Hello World!\") == 0: " << 
                (greeting.compare("Hello World!") == 0) << std::endl << std::endl;
    

    std::cout << "Value of npos: " << std::string::npos << std::endl;
    std::cout << "npos == -1: " << (std::string::npos == -1) << std::endl;
    return 0;
}