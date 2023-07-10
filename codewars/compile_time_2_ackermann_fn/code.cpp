#include <assert.h>
#include <iostream>


template <int m, int n>
struct ackermann {
    enum
    {
        value = ackermann<m - 1, ackermann<m, n - 1>::value>::value
    };
};

template<int n>
struct ackermann<0, n>
{
    enum
    {
        value = n + 1
    };
};

template<int m>
struct ackermann<m, 0>
{
    enum
    {
        value = ackermann<m - 1, 1>::value
    };
};

template<>
struct ackermann<0, 0>
{
    enum
    {
        value = 1
    };
};



int main()
{
    static_assert(ackermann<2, 2>::value == 7, "");
    assert((ackermann<2, 2>::value) == 7);
    return 0;
}