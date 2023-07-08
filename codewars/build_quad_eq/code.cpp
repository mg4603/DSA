#include <assert.h>
#include <iostream>

#include <string>
#include <sstream>

int strIntParser(std::string str)
{
    int res;
    bool neg((str[0] == '-')?1:0);
    try
    {
        res = stoi(str);
    }
    catch(std::invalid_argument)
    {
        if(neg)
        {
            res = -1;
        }
        else
        {
            res = 1;
        }
    }
    return res;
}

std::string quadratic_builder(const std::string& expression)
{
    std::string symbols("-+*/");
    int m(strIntParser(expression.substr(1)));
    int n(strIntParser(expression.substr(expression.find_first_of(symbols, 2))));
    int p(strIntParser(expression.substr(expression.find_first_of('(', 2) + 1)));
    int q(strIntParser(expression.substr(expression.find_last_of(symbols))));

    int a = m * p;
    int b = (m * q + n * p);
    int c = (n * q);

    char ch(expression.substr(expression.find_first_not_of("-+*/()0123456789"))[0]);
    std::stringstream ss;
    
    if(a != 1 && a != -1)
    {
        ss << a << ch << "^2";
    }
    else if(a == 1)
    {
        ss << ch << "^2";
    }
    else
    {
        ss << "-" << ch << "^2";
    }

    if(b < -1)
    {
        ss << b << ch;
    }
    else if(b > 1)
    {
        ss << "+" << b << ch;
    }
    else
    {
        switch(b)
        {
            case -1:
                ss << '-' << ch;
                break;
            case 1:
                ss << '+' << ch;
                break;
        }
    }

    if(c < 0)
    {
        ss << c;
    }
    else if(c > 0)
    {
        ss << "+" << c;
    }
    
    return ss.str();
}

template <class T1, class T2>
void assert_equals(T1 expected, T2 actual)
{
    assert(expected == actual);
}

int main()
{
    assert_equals(quadratic_builder("(-h-7)(4h+3)"), "-4h^2-31h-21");
    assert_equals(quadratic_builder("(x+2)(x+3)"), "x^2+5x+6");
    assert_equals(quadratic_builder("(x-2)(x+7)"), "x^2+5x-14");
    assert_equals(quadratic_builder("(3y+2)(y+5)"), "3y^2+17y+10");
    return 0;
}