#include <iostream>

// pass by reference to reflect changes made to parameters in the function
// to arguments in the calling function's scope
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
    std::cout << "In swap:\n";
    std::cout << "a: " << a << " b: " << b << std::endl;
}
int main()
{
    std::cout << "Pass by Reference\n\n";
    int a = 5;
    int b = 10;
    std::cout << "Before swap: \n";
    std::cout << "a: " << a << " b: " << b << std::endl;
    swap(a, b);
    std::cout << "After swap: \n";
    std::cout << "a: " << a << " b: " << b << std::endl;

    return 0;
}