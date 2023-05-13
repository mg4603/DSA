#include <assert.h>
#include <iostream>

#include <string>

std::string string_expansion(const std::string& s) {
    std::string res;
    size_t lastMul(1);
    for(size_t i(0); i < s.size(); i++)
    {
        if(isalpha(s[i]))
        {
            if(i > 0)
            {
                if(isdigit(s[i - 1]))
                {
                    lastMul = s[i - 1] - '0';
                }
                res += std::string(lastMul, s[i]);
            }
            else
            {
                res += s[i];
            }
        }
    }
    return res;
}

int main()
{
    assert(string_expansion("3abc") == "aaabbbccc");
    assert(string_expansion("3D2a5d2f") == "DDDaadddddff");
    assert(string_expansion("0d0a0v0t0y") == "");
    assert(string_expansion("3d332f2a") == "dddffaa");
    assert(string_expansion("abcde") == "abcde");
    return 0;
}