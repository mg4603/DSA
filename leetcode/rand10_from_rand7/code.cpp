#include <iostream>
#include <assert.h>

#include <limits>
#include <random>

class Solution {
    int rand7()
    {
        return 1 + (rand() % 7);
    }
public:
    int rand10() 
    {
        int res = std::numeric_limits<int>::max();
        while(res >= 40)
        {
            res = 7 * (rand7() - 1) + (rand7() - 1);
        }
        return (res % 10) + 1;
    }
};

int main()
{
    return 0;
}