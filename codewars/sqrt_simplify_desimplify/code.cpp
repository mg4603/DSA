#include <iostream>
#include <assert.h>

#include <string>
#include <sstream>

#include <cmath>

std::string simplify(int n)
{
    int rt(0);
    int rm(0);
    for(int i(1); i <= sqrt(n); i++)
    {
        if(n % (i * i) == 0)
        {
            rt = i;
            rm = n / (i * i);
        }
    }
    std::stringstream ss;
    
    if(rm == 1)
    {
        ss << rt;
    }
    else if(rt == 0 || rt == 1)
    {
        ss << "sqrt " << rm;
    } 
    else
    {
        ss << rt << " sqrt " << rm;
    }
    return ss.str();
}

int desimplify(std::string s)
{
    int rt;
    if(isdigit(s[0]))
    {
        rt = stoi(s);
    }
    else
    {
        rt = 1;
    }

    int rm;
    size_t pos(s.find("sqrt"));
    if(pos == std::string::npos)
    {
        rm = 1;
    }
    else
    {
        rm = stoi(s.substr(pos + 4));
    }

    return rt * rt * rm;
}

void should_desimplify()
{
    assert(desimplify("1") == 1);
    assert(desimplify("sqrt 2") == 2);
    assert(desimplify("sqrt 3") == 3);
    assert(desimplify("2 sqrt 2") == 8);
    assert(desimplify("sqrt 15") == 15);
    assert(desimplify("4") == 16);
    assert(desimplify("3 sqrt 2") == 18);
    assert(desimplify("2 sqrt 5") == 20);
    assert(desimplify("2 sqrt 6") == 24);
    assert(desimplify("4 sqrt 2") == 32);
}

void should_simplify()
{
    assert(simplify(1) == "1");
    assert(simplify(2) == "sqrt 2");
    assert(simplify(3) == "sqrt 3");
    assert(simplify(8) == "2 sqrt 2");
    assert(simplify(15) == "sqrt 15");
    assert(simplify(16) == "4");
    assert(simplify(18) == "3 sqrt 2");
    assert(simplify(20) == "2 sqrt 5");
    assert(simplify(24) == "2 sqrt 6");
    assert(simplify(32) == "4 sqrt 2");
}

int main()
{
    should_desimplify();
    should_simplify();
    return 0;
}