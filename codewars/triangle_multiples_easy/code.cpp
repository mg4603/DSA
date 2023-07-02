#include <iostream>
#include <assert.h>

#include <array>

std::array<unsigned long, 3> multTriangle(const unsigned int n) {

    std::array<unsigned long, 3> res{0};

    for(int i(1); i <= n; i++)
    {

        for(unsigned int j(1); j <= i; j++)
        {
            unsigned long temp(i * j);
            if((temp) % 2 )
            {
                res[2] += temp;
            }
            else
            {
                res[1] += temp;
            }
            res[0] += temp;
        }
        for(unsigned int j(i-1); j >= 1; j--)
        {
            unsigned long temp(i * j);
            if((temp) % 2 )
            {
                res[2] += temp;
            }
            else
            {
                res[1] += temp;
            }
            res[0] += temp;
        }

    }
    return res;
}

int main()
{
    unsigned int n = 1;
    std::array<unsigned long, 3> mult = {1, 0, 1};
    assert(multTriangle(n) == mult );
    n = 2, mult = {9, 8, 1};
    assert(multTriangle(n) == mult);
    n = 3, mult = {36, 20, 16};
    assert(multTriangle(n) == mult);
    n = 4, mult = {100, 84, 16};
    assert(multTriangle(n) == mult);
    n = 5, mult = {225, 144, 81};
    assert(multTriangle(n) == mult);
    return 0;
}