#include <iostream>
#include <assert.h>


#include <algorithm>
#include <string>
#include <cmath>
#include <list>

std::string whitespace_number(int n)
{
    std::list<char> res;
    bool neg(0);
    if(std::signbit(n) == 1)
    {
        neg = 1;
        n = -n;
    }
    while(n)
    {   
        if(n % 2 == 0)
        {
            res.push_front(' ');
        }
        else
        {
            res.push_front('\t');
        }
        n /= 2;
    }

    if(neg)
    {
        res.push_front('\t');
    }
    else
    {
        res.push_front(' ');
    }

    res.push_back('\n');
    return std::string(begin(res), end(res));
}

std::string unbleach(std::string s)
{
    std::string res;
    for(char c: s)
    {
        if(c == ' ')
        {
            res += "[space]";
        }
        else if(c == '\n')
        {
            res += "[LF]";
        }
        else
        {
            res += "[tab]";
        }
    }
    return res;
}

void doTest(int n, const std::string &expected)
{
    std::cout << "n = " << n << std::endl;
    const std::string ws(" \t\n"), actual = whitespace_number(n);
    if ( any_of(begin(actual), end(actual), [=](char c){return ws.find(c) == std::string::npos;}) )
        std::cout << "Please return only spaces, tabs and newlines. "
                << "Other characters are not allowed.\n"
                << "Tests will convert the allowed characters"
                << " to readable tags for your convenience." << std::endl;
    assert(unbleach(actual) == unbleach(expected));
}

int main()
{
    doTest( 1,    " \t\n");
    doTest( 0,      " \n");
    doTest(-1,   "\t\t\n");
    doTest( 2,   " \t \n");
    doTest(-3, "\t\t\t\n");
}
