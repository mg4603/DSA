#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    std::vector<double> convertTemperature(double celsius) 
    {
        std::vector<double> res(2, 0.0);
        res[0] = celsius + 273.15;
        res[1] = celsius * 1.80 + 32.00;
        return res;
    }
};

int main()
{
    Solution sol;
    {
        double celsius = 36.50;
        std::vector<double> res = {309.65000,97.70000};
        assert(sol.convertTemperature(celsius) == res);
    }
    {
        double celsius = 122.11;
        std::vector<double> res = {395.26000,251.79800};
        assert(sol.convertTemperature(celsius) == res);
    }
    return 0;
}