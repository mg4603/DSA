#include <assert.h>
#include <iostream>

#include <sstream>

std::string pattern(int n)
{
    std::stringstream ss;
    for(int i(1); i <= n; i++)
    {
        if(i > 1)
            ss << '\n';

        if(i > 1)
            ss << std::string(i - 1, ' ');
        ss << i;
        if(2 * (n - i) > 1)
        {
            ss << std::string(2 * (n - i) - 1, ' ');
            ss << i;
        }
        if(i > 1)
            ss << std::string(i - 1, ' ');
    }
    for(int i(n-1); i >= 1; i--)
    {
        ss << '\n';
        if(i > 1)
            ss << std::string(i - 1, ' ');
        ss << i;
        if(2 * (n - i) > 1)
        {
            ss << std::string(2 * (n - i) - 1, ' ');
            ss << i;
        }
        if(i > 1)
            ss << std::string(i - 1, ' ');
    }
    return ss.str();
}

void basicTest1(){
    std::string expected = "\n"
        "1   1\n"
        " 2 2 \n"
        "  3  \n"
        " 2 2 \n"
        "1   1";
    
    std::string actual = "\n" + pattern(3);

    assert(actual == expected);
}

void basicTest2(){
    std::string expected = "\n"
        "1       1\n"
        " 2     2 \n"
        "  3   3  \n"
        "   4 4   \n"
        "    5    \n"
        "   4 4   \n"
        "  3   3  \n"
        " 2     2 \n"
        "1       1";
    
    std::string actual = "\n" + pattern(5);

    assert(actual == expected);
}

int main()
{
    basicTest1();
    basicTest2();
    return 0;
}