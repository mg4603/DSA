#include <iostream>

// function overloading:
//      * the creation of multiple functions that share the same name but have
//        different signatures
//      * function signatures in c++ are independent of the return type
//          and pass by value or pass by reference.
// 

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void swap(std::string &a, std::string &b)
{
    std::string temp = a;
    a = b;
    b = temp;
}

int main()
{
    std::cout << "Function Overloading Part 1\n\n";

    // calling swap with two integers will call the overload with int arguments
    int a = 5;
    int b = 10;

    std::cout << "Before swap: \n";
    std::cout << "a: " << a << "\tb: " << b << std::endl;
    swap(a, b);
    std::cout << "After swap: \n";
    std::cout << "a: " << a << "\tb: " << b << std::endl << std::endl;

    // calling swap with two strings will call the overload with string arguments
    std::string str1 = "hello";
    std::string str2 = "world";

    std::cout << "Before swap: \n";
    std::cout << "str1: " << str1 << "\tstr2: " << str2 << std::endl;
    swap(str1, str2);
    std::cout << "After swap: \n";
    std::cout << "str1: " << str1 << "\tstr2: " << str2 << std::endl;

    return 0;
}