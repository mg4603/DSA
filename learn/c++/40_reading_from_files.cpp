#include <fstream>
#include <iostream>
#include <vector>

template <typename t> 
void print_vector(std::vector<t> data)
{
    for(t ele: data)
    {
        std::cout << ele << std::endl;
    }
}

int main()
{
    std::cout << "Reading from Files\n\n";

    // declare ifstream object
    // std::ifstream file;

    // initialize ifstream object
    // file.open("file.txt");

    // declare and initialize ifstream object
    std::ifstream file("hello.txt");

    std::vector<std::string> data_ws;
    // ifstream object can be used in a similar manner to cin
    std::string temp;

    // whitespace is data separator
    // while(file >> temp) // file >> temp returns the stream which evaluates to 
    // {                   // true if read was successful
        // data_ws.push_back(temp);
    // }

    // std::cout << "Data in file with whitespace as separator: \n";
    // print_vector<std::string>(data_ws);

    // get a single character
    // file.get()

    // check if file opened successfully
    if(file.is_open())
    {
        // new line as separator
        getline(file, temp);
        std::cout << "Data in file with new line as separator: \n";
        std::cout << temp << std::endl;;
    }
    else
    {
        std::cout << "Error opening file\n";
        return -1;
    }
    return 0;
}