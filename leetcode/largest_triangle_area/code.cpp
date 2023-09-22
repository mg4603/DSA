#include <iostream>
#include <assert.h>

#include <vector>
#include <cmath>

class Solution {
public:
    double largestTriangleArea(std::vector<std::vector<int>>& points) {
        double res(0.0);
        for(auto point1: points)
        {
            for(auto point2: points)
            {
                for(auto point3: points)
                {

                    double a = std::sqrt(
                                std::pow(point1[0] - point2[0], 2) +
                                std::pow(point1[1] - point2[1], 2));

                    double b = std::sqrt(
                                std::pow(point1[0] - point3[0], 2) +
                                std::pow(point1[1] - point3[1], 2));

                    double c = std::sqrt(
                                std::pow(point2[0] - point3[0], 2) +
                                std::pow(point2[1] - point3[1], 2));

                    double s = (a + b + c) / 2.0;
                    
                    double area = std::sqrt(s * (s - a) * (s - b) * (s - c));
                    res = std::max(res, area);
                }
            }
        }
        
        return res;
    }
};
void fuzzy_equal(double a, double b)
{

    assert(std::abs(a - b) <= 10e-5);
}
int main()
{
    Solution sol;
    {
        std::vector<std::vector<int>> points = {
            {0,0},{0,1},{1,0},{0,2},{2,0}
        };
        double output = 2.00000;
        fuzzy_equal(sol.largestTriangleArea(points), output);
    }
    {
        std::vector<std::vector<int>> points = {
            {1,0},{0,0},{0,1}
        };
        double output = 0.50000;
        fuzzy_equal(sol.largestTriangleArea(points), output);
    }
    return 0;
}