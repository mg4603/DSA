#include <assert.h>
#include <iostream>

static int pointsNumber(int radius)
{
    int pts(1 + 4 * radius);
    int nLine(0);
    for(int i(1); i < radius; i++)
    {
        for(int j(1); j < radius; j++)
        {
            if(radius * radius >= (i * i) + (j * j))
            {
                nLine++;
            }
        }
    }
    return pts + (4 * nLine);
}

int main()
{
    assert(pointsNumber(1) ==5);
    assert(pointsNumber(2) ==13);
    assert(pointsNumber(3) ==29);
    assert(pointsNumber(5) ==81);
    assert(pointsNumber(1000) ==3141549);
    return 0;
};