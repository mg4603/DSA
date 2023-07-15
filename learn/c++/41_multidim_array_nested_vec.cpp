#include <iostream>
#include <vector>

int main()
{
    std::cout << "Multidimensional Arrays and Nested Vectors\n\n";
    // for c-style multidimensional arrays, the max size of the inner 
    // arrays must be explicitly defined
    int array2d[][3] = {
        {1, 2, 3}, 
        {4, 5, 6}, 
        {7, 8, 9}};

    std::cout << "Data in 2d array:\n";
    // iterating through a 2d array
    for(int i(0); i < 3; i++)
    {
        for(int j(0); j < 3; j++)
        {
            std::cout << array2d[i][j] << '\t';
        }
        std::cout << std::endl;
    }

    // nested vectors
    std::vector<std::vector<int>> vec2d = {
        {11, 22, 33},
        {44, 55, 66},
        {77, 88, 99}
    };

    std::cout << "Data in 2d vector:\n";
    // iterating through a 2d vector
    for(int i(0); i < 3; i++)
    {
        for(int j(0); j < 3; j++)
        {
            std::cout << vec2d[i][j] << '\t';
        }
        std::cout << std::endl;
    }
    return 0;
}