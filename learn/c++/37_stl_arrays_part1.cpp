#include <iostream>
#include <array>

void print_array(std::array<int, 5> array, int size)
{
    for(int i(0); i < size; i++)
    {
        std::cout << array[i] << ' ';
    }
    std::cout << std::endl;
}

int main()
{
    std::cout << "STL Arrays Part 1\n\n";
    // statically sized
    // wrapped with an object that remembers size
    // passed by value to function:
    //      unless passed by reference, a copy of the stl array is created in 
    //      the function parameter and all manipulations occur on the copy
    // 

    // declaration
    std::array<int, 20> data_dec;  // create an array of size 20
    // declare and initialize 
    //          partial initialization results in uninitialized value being 
    //          set to 0
    std::array<int, 5> data_init{1, 2, 3};

    // size of array
    std::cout << "Size of data_init array: " << data_init.size() << 
            std::endl << std::endl;

    std::cout << "Elements of data_init array: ";
    print_array(data_init, 3);
    std::cout << std::endl;
    return 0;
}