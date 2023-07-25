#include <iostream>
#include <assert.h>
#include <cmath>

class Transform{
    static bool isPowTwo(int n);
public:
    static int operation(int a, int b);
};

bool Transform::isPowTwo(int n)
{
    if(log2(n) == floor(log2(n)))
    {
        return true;
    }
    return false;
}

int Transform::operation(int a, int b)
{
    int cnt(0);
    while(!isPowTwo(a))
    {
        a /= 2;
        cnt++;
    }
    return std::abs(log2(b) - log2(a)) + cnt;
}

int main()
{
    assert(Transform::operation(1,1) == 0);
    assert(Transform::operation(4,1) == 2);
    assert(Transform::operation(1,4) == 2);
    return 0;
}