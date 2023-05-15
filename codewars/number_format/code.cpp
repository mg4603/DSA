#include <assert.h>
#include <iostream>

#include<string>

std::string numberFormat(long long n){
    bool neg(0);
    if(n < 0)
    {
        neg = 1;
        n = -n;
    }

    std::string res;
    int grp(0);
    std::string n_str(std::to_string(n));

    for(size_t i(n_str.size()); i > 0; i--)
    {
        res = n_str[i - 1] + res;
        grp++;
        if(grp == 3 && i != 1)
        {
            res = ',' + res;
            grp = 0;
        }
    }

    if(neg)
    {
        return '-' + res;
    }
    return res;
}

int main()
{
    assert(numberFormat(-420902) == "-420,902");
    assert(numberFormat(100000) == "100,000");
    assert(numberFormat(5678545) == "5,678,545");
    assert(numberFormat(3) == "3");
    assert(numberFormat(-3) == "-3");
    return 0;
}