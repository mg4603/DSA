#include <iostream>

template <typename T>
void swap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

int main()
{
    std::cout << "Function Templates\n\n";

    // calling templatized swap with int
    int a = 5;
    int b = 10;
    std::cout << "Integers before swap:\n";
    std::cout << "a: " << a << "\tb: " << b << std::endl;
    swap(a, b);
    std::cout << "Integers after swap:\n";
    std::cout << "a: " << a << "\tb: " << b << std::endl << std::endl;
    
    // calling templatized swap with string
    std::string str1 = "hello";
    std::string str2 = "world";
    std::cout << "Strings before swap:\n";
    std::cout << "str1: " << str1 << "\tstr2: " << str2 << std::endl;
    swap(str1, str2);
    std::cout << "Strings after swap:\n";
    std::cout << "str1: " << str1 << "\tstr2: " << str2 << std::endl;
    return 0;
}