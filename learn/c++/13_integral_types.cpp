#include <iostream>
#include <limits>

// sizeof is an operator not a function

int main()
{
    std::cout << "In Integral data types: " << std::endl;
    // four primary integral datatypes
    // difference depends on the amount of memory allocated
    // short <= int <= long <= long long
    // atleast 8 bits
    short a;
    std::cout << "Size of short: " << sizeof(short) << std::endl;
    std::cout << "Max short: " << std::numeric_limits<short>::max() 
                << std::endl;
    std::cout << "Min short: " << std::numeric_limits<short>::min() 
                << std::endl << std::endl;

    // atleast 16 bits are allocated but usually 32 bits
    int b;
    std::cout << "Size of int: " << sizeof(b) << std::endl;
    std::cout << "Max int: " << std::numeric_limits<int>::max() 
                << std::endl;
    std::cout << "Min int: " << std::numeric_limits<int>::min() 
                << std::endl << std::endl;
    
    // atleast 32 bits
    long c;
    std::cout << "Size of long: " << sizeof(c) << std::endl;
    std::cout << "Max long: " << std::numeric_limits<long>::max() 
                << std::endl;
    std::cout << "Min long: " << std::numeric_limits<long>::min() 
                << std::endl << std::endl;

    // atleast 64 bits
    long long d;
    std::cout << "Size of long long: " << sizeof(d) << std::endl;
    std::cout << "Max long long: " << std::numeric_limits<long long>::max() 
                << std::endl;
    std::cout << "Min long long: " << std::numeric_limits<long long>::min() 
                << std::endl << std::endl;

    // unsigned counterparts of primary integral datatypes
    // only allow positive values
    // doubles max possible value
    unsigned short aa;
    std::cout << "Size of unsigned short: " << sizeof(aa) << std::endl;
    std::cout << "Max unsigned short: " 
                << std::numeric_limits<unsigned short>::max() 
                << std::endl;
    std::cout << "Min unsigned short: " 
                << std::numeric_limits<unsigned short>::min() 
                << std::endl << std::endl;

    unsigned int bb;
    std::cout << "Size of unsigned int: " << sizeof(bb) << std::endl;
    std::cout << "Max unsigned int: " 
                << std::numeric_limits<unsigned int>::max() 
                << std::endl;
    std::cout << "Min unsigned int: " 
                << std::numeric_limits<unsigned int>::min() 
                << std::endl << std::endl;

    unsigned long cc;
    std::cout << "Size of unsigned long: " << sizeof(cc) << std::endl;
    std::cout << "Max unsigned long: " 
                << std::numeric_limits<unsigned long>::max() 
                << std::endl;
    std::cout << "Min unsigned long: " 
                << std::numeric_limits<unsigned long>::min() 
                << std::endl << std::endl;

    unsigned long long dd;
    std::cout << "Size of unsigned long long: " << sizeof(dd) << std::endl;
    std::cout << "Max unsigned long long: " 
                << std::numeric_limits<unsigned long long>::max() 
                << std::endl;
    std::cout << "Min unsigned long long: " 
                << std::numeric_limits<unsigned long long>::min() 
                << std::endl << std::endl;

    return 0;
}