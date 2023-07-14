#include <iostream>

int main()
{
    std::cout << "Arrays Part 1\n\n";

    // declare an array of type int with size 23
    int example_dec[23];
    
    // declare and initialize - size is implicitly set to 6
    // the implicitly set size can't be modified
    // can be used when all data is known ahead of time
    int example_init[10] = {10, 13, 54, 42, 12, 13};

    int num_elems(6);
    int size(sizeof(example_init)/ sizeof(int));
    // iterating through a c-style array
    std::cout << "Iterating through example_init: ";
    for(int i(0); i < size; i++)
    {
        std::cout << example_init[i] << ' ';
    }
    std::cout << std::endl;
    std::cout << "Iterating through elements of example_init: ";
    for(int i(0); i < num_elems; i++)
    {
        std::cout << example_init[i] << ' ';
    }
    std::cout << std::endl << std::endl;;

    return 0;
}