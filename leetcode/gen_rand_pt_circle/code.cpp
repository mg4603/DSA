#include <iostream>
#include <assert.h>

#include <vector>
#include <cmath>

class Solution {
    double r;
    double x0;
    double y0;
public:
    Solution(double radius, double x_center, double y_center) 
    {
        r = radius;
        x0 = x_center;
        y0 = y_center;
    }
    double random()
    {
        return static_cast<double>(rand()) / RAND_MAX;
    }

    std::vector<double> randPoint() 
    {
        double len = std::sqrt(random()) * r;
        double deg = 2 * M_PI * random();

        double x = x0 + len * std::cos(deg);
        double y = y0 + len * std::sin(deg);
        return {x, y};
    }
};

int main()
{
    return 0;
}