#include <iostream>

// use of const modifier for array parameters prevents it's modification
// inside of a function.
// This ensures data integrity inside called function for the caller 
// function.
// A non-const argument can be passed into an function that takes a 
// const parameter. The const modifier says that, that parameter can't be 
// modified inside of that function.
// 
void print_array(const int array[], int size)
{
    for(int i(0); i < size; i++)
    {
        std::cout << array[i] << '\t';
    }
    std::cout << std::endl;
}

int main()
{
    std::cout << "Const Modifier\n\n";
    int array[] = {1, 2, 3};
    std::cout << "Data in array: \n";
    print_array(array, 3);
    return 0;
}