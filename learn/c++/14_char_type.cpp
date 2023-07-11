#include <iostream>
#include <limits>
int main()
{
    std::cout << "In char type " << std::endl;
    // 8 bits - an integral data type
    char x = 'A';
    std::cout << x << std::endl;
    std::cout << "Cast char to int: " << (int) x << std::endl;
    char a = 65;
    // Number 65 is implicitly interpreted as ascii char unless cast to int
    std::cout <<  a << ' ' << (int) a << std::endl << std::endl;
    
    // overflow
    //      * if we try to store a number larger than the largest number that
    //        can be stored in a variable, the number stored becomes
    //        (a % MAX_VALUE_THAT_CAN_BE_STORED + 1) + MIN_VALUE_THAT_CAN_BE_STORED

    // signed char
    std::cout << "Min char value: " << (int) std::numeric_limits<char>::min() 
                << std::endl;
    std::cout << "Max char value: " << (int) std::numeric_limits<char>::max() 
                << std::endl;
    a = 127;
    std::cout << "127 ==> " << (int) a << std::endl;
    a = 128;
    std::cout << "128 ==> " << (int) a << std::endl;
    a = 129;
    std::cout << "129 ==> " << (int) a << std::endl << std::endl;

    // unsigned char
    std::cout << "Min unsigned char value: " << 
                (int) std::numeric_limits<unsigned char>::min() << std::endl;
    std::cout << "Max unsigned char value: " <<
                (int) std::numeric_limits<unsigned char>::max() << std::endl;
    unsigned char b = 255;
    std::cout << "255 ==> " << (unsigned) b << std::endl;
    b = static_cast<unsigned char>(256);
    std::cout << "256 ==> " << (unsigned) b << std::endl;
    return 0;
}