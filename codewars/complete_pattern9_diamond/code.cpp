#include <assert.h>
#include <iostream>

#include <string>
#include <sstream>
#include <iomanip>

std::string pattern(int n)
{
    std::stringstream ss;
    for(int i(1); i <= n; i++)
    {
        ss << std::string(n - i, ' ');
        for(int j(1); j <= i; j++)
        {
            ss <<(j % 10);
        }
        for(int j(i - 1); j > 0; j--)
        {
            ss << (j % 10);
        }
        ss << std::string(n - i, ' ') << '\n';
    }

    for(int i(n - 1); i > 0; i--)
    {
        ss << std::string(n - i, ' ');
        for(int j(1); j <= i; j++)
        {
            ss << (j % 10);
        }
        for(int j(i - 1); j > 0; j--)
        {
            ss << (j % 10);
        }
       
        ss << std::string(n - i, ' ') << '\n';
    }
    
    std::string res(ss.str());

    if(res.back() == '\n')
    {
        res.pop_back();
    }
    return res;
}

int main()
{
    std::string expected = "      1      \n     121     \n    12321    \n   1234321   \n  123454321  \n 12345654321 \n1234567654321\n 12345654321 \n  123454321  \n   1234321   \n    12321    \n     121     \n      1      ";
    std::string actual = pattern(7);
    assert(actual == expected);
    
    expected = "1";
    actual = pattern(1);
    assert(actual == expected);

    expected = "  1  \n 121 \n12321\n 121 \n  1  ";
    actual = pattern(3);
    assert(actual == expected);
    
    expected = "";
    actual = pattern(0);
    assert(actual == expected);
    
    expected = "";
    actual = pattern(-25);
    assert(actual == expected);
    return 0;
};