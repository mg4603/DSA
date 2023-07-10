#include <assert.h>
#include <iostream>

template <unsigned long long x>
struct factorial { 
    enum
    {
        value  = x * factorial<x - 1>::value
    };
};

template <>
struct factorial<0>
{
    enum
    {
        value = 1
    };
};


int main()
{
    static_assert(factorial<4>::value == 24, "");
    assert(factorial<3>::value ==  6);
    assert(factorial<4>::value == 24);
}