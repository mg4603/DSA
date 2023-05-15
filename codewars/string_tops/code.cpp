#include <iostream>
#include <assert.h>

#include <string>

std::string tops(const std::string& msg)
{
    std::string res;
    size_t idx(0);
    for(size_t i(1); idx < msg.size(); i+=2)
    {
        idx += i;
        if(isalnum(msg[idx]))
        {
          res = msg[idx] + res;
        }
        idx += i + 1;
    }
    return res;
}

int main()
{
    assert(tops("") == "");
    assert(tops("12") == "2");
    assert(tops("abcdefghijklmnopqrstuvwxyz12345") == "3pgb");
    assert(tops("abcdefghijklmnopqrstuvwxyz1236789ABCDEFGHIJKLMN") == "M3pgb");
    return 0;
}