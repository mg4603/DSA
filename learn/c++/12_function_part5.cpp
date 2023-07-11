#include <iostream>
#include <cmath>
#include <sstream>
#include <map>

// a function should only do one thing and that one thing should be described
// by the identifier

double power(double base, int exponent)
{
    double result(1);
    for(int i(0); i < exponent; i++)
    {
        result *= base;
    }
    return result;
}

// void functions
//      functions that do something but don't return a value
void print_pow(double base, int exponent)
{
    std::map<int, std::string> ordinal_endings{{1, "st"}, {2, "nd"}, {3, "rd"}};
    std::stringstream ss;
    double myPower(power(base, exponent));

    ss << base << " raised to the " << exponent;
    if(ordinal_endings.count(exponent % 10))
    {
        ss << ordinal_endings[exponent % 10];
    }
    else
    {
        ss << "th";
    }

    ss << " power is " << myPower << '.';
    std::cout << ss.str() << std::endl;
}

template<typename T>
T read_num(std::string prompt = "")
{
    if(prompt != "")
    {
        std::cout << prompt << std::endl;
    }
    T input;
    std::cin >> input;
    return input;
}

int main()
{
    std::cout << "In function part 5" << std::endl;
    double base(read_num<double>("What is the base?"));
    int exponent(read_num<int>("What is the exponent?"));
    print_pow(base, exponent);
    return 0;
}