#include <iostream>

int main()
{
    std::cout << "Control Flow Part 5: Break and Continue\n\n";
    // break    : break out of the current loop when encountered
    std::string greeting = "Hello World!";

    std::cout << "Searching for first o in greeting: " ;
    for(int i(0); i < greeting.size(); i++)
    {
        std::cout << greeting[i];
        if(greeting[i] == 'o')
        {
            std::cout << std::endl << "Found first o!\n\n";
            break;
        }
    }

    // continue : skip the rest of the current interation of the current loop
    //              when encountered
    
    std::cout << "Removing o(s) from greeting: ";
    for(int i(0); i < greeting.size(); i++)
    {
        if(greeting[i] == 'o')
        {
            continue;
        }
        std::cout << greeting[i];
    }
    std::cout << std::endl << std::endl;
    return 0;
}