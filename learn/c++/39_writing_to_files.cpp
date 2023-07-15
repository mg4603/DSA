#include <fstream>
#include <iostream>

int main()
{
    std::cout << "Writing to Files Part 1\n\n";
    // need to create a ofstream object which can then be used in a similar
    // manner to cout
    // 
    // declaring ofstream object
    std::ofstream file;
    // initializing ofstream object
    file.open("hello.txt");

    // simultaneous declaration and initialization
    // std::ofstream file("hello.txt");

    // if you wish to append to file - add second argument "std::ios::app"

    // check if file opened successfully
    if(file.is_open())
    {
        // write to file
        file << "Hello World!";    
        std::cout << "Successfully written to file\n";
    }
    else
    {
        std::cout << "File failed to open\n";
        return -1;
    }
    // close file
    file.close();
    return 0;
}