#include <iostream>
#include <assert.h>

#include <vector>
#include <algorithm>

class Ball
{
    public: static int maxBall(int v0);
};

int Ball::maxBall(int v0)
{
    std::vector<double> recs;
    double v_ms(v0 * 5 / 18.0);
    recs.push_back(0.0);
    int i(1);
    while(true)
    {
        double h(v_ms * i * 0.1 - 0.5 * 9.81 * (i * 0.1) * (i * 0.1));
        if(h <= 0)
        {
            break;
        }
        recs.push_back(h);
        i++;
    }
    return std::max_element(recs.begin(), recs.end()) - recs.begin();
}

void testequal(int ans, int sol) {
    assert(ans == sol);
}

int main()
{
    testequal(Ball::maxBall(37), 10);
    testequal(Ball::maxBall(45), 13);
    testequal(Ball::maxBall(99), 28);
    testequal(Ball::maxBall(85), 24);
        return 0;
}