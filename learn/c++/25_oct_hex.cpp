#include <iostream>

int main()
{
    std::cout << "Octal and Hexadecimal numbers" << std::endl << std::endl;
    // define octal numbers by prefixing with 0
    int octal_num(030); // 0 * 1 + 3 * 8 = 24
    std::cout << "octal 30 to int: " << octal_num << std::endl;
    
    // define hex numbers by prefixing with 0x
    int hex_num(0x10); // 0 * 1 + 1 * 16 = 16;
    std::cout << "hexadecimal 10 to int: " << hex_num << std::endl << std::endl;

    int num(100);
    std::cout << "int 100 to oct: " << std::oct << num << std::endl;
    std::cout << "int 100 to hexadecimal: " << std::hex << num << std::endl;
    return 0;
}