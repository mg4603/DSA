#include <iostream>
#include <vector>

int main()
{
    std::cout << "Vectors Part 1\n\n";

    // declare a vector
    std::vector<int> data_dec;
    // declare and initialize vector
    std::vector<int> data_init ({1, 2, 3});
    // add element to vector
    data_init.push_back(100);
    
    // get vector element
    std::cout << "4th element of vector data_init: " << data_init[3] << 
                std::endl << std::endl;

    // get size of vector
    std::cout << "Size of vector data_init: " << data_init.size() << 
                std::endl << std::endl;
    
    // remove last element of vector
    std::cout << "Last element of vector data_init before pop_back: " << 
                data_init[data_init.size() - 1] << std::endl;
    std::cout << "Size of vector data_init before pop_back: " << 
                data_init.size() << std::endl;
    data_init.pop_back();
    std::cout<< "Last element of vector data_init after pop_back: " << 
                data_init[data_init.size() - 1] << std::endl;
    std::cout << "Size of vector data_init after pop_back: " << 
                data_init.size() << std::endl;
    return 0;
}