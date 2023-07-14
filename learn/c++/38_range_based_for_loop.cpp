#include <iostream>
#include <vector>
#include <array>

int main()
{
    std::cout << "Range Based For Loop\n\n";
    // Range based for loops are used to iterate through collections
    // 
    // In statically sized containers, use of range based for loops can result
    // unexpected outcome if the collection is not completely initialized
    // 
    // Trying to use range based for loops with c-style arrays, outside of
    // the scope in which it is defined will result in a compilation error
    // due to the array decaying to a pointer that doesn't store size information
    // 
    int array[6] = {1, 2, 3, 4, 5, 6};
    std::cout << "Array contents: ";
    for(int num: array)
    {
        std::cout << num <<  ' ';
    }
    std::cout << std::endl << std::endl;

    std::vector<int> vec = {1, 2, 3, 4, 5};
    std::cout << "Vector contents: ";
    for(int num: vec)
    {
        std::cout << num << ' ';
    }
    std::cout << std::endl << std::endl;

    std::array<int, 6> templatized_array = {1, 2, 3, 4, 5, 6};
    std::cout << "Templatized array contents: ";
    for(int num: templatized_array)
    {
        std::cout << num << ' ';
    }
    std::cout << std::endl << std::endl;
    return 0;
}