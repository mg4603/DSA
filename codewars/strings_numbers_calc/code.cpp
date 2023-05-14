#include <assert.h>
#include <iostream>

#include <string>
#include <cmath>

std::string calculateString(std::string calcIt) 
{
    std::string result = "";
    std::string symbols = "*/+-";
    for(char c: calcIt)
    {
        if(isdigit(c) || c == '.' || symbols.find(c) != std::string::npos)
        {
            result += c;
        }
    }
    double a = std::stod(result);
    double b = std::stod(result.substr(result.find_first_of(symbols) + 1));
    char symbol = result[result.find_first_of(symbols)];
    switch(symbol)
    {
        case '+':
            return std::to_string(int(round(a + b)));
        case '-':
            return std::to_string(int(round(a - b)));
        case '/':
            return std::to_string(int(round(a / b)));
        case '*':
            return std::to_string(int(round(a * b)));
        default:
            return "";
    }
    
}   

void test1()
{
    std::string expected = "47";
    std::string actual = calculateString(";$%§fsdfsd235??df/sdfgf5gh.000kk0000");

    assert(actual == expected);
}

void test2()
{
    std::string expected = "54929268";
    std::string actual = calculateString("sdfsd23454sdf*2342");

    assert(actual == expected);
}

void test3()
{
    std::string expected = "-210908";
    std::string actual = calculateString("fsdfsd235???34.4554s4234df-sdfgf2g3h4j442");

    assert(actual == expected);
}

void test4()
{
    std::string expected = "234676";
    std::string actual = calculateString("fsdfsd234.4554s4234df+sf234442");

    assert(actual == expected);
}

int main()
{
    test1();
    test2();
    test3();
    test4();
    return 0;
}