#include <iostream>
#include <assert.h>

#include <vector>
#include <cmath>

class Solution {
public:
    std::vector<int> constructRectangle(int area) {
        int n(std::sqrt(area));
        while(n >= 1)
        {
            if(area % n == 0)
            {
                return {area / n, n};
            }
            n--;
        }
        return {area, 1};
    }
};

int main()
{
    Solution sol;
    {
        assert(sol.constructRectangle(4) == std::vector<int>(
                                                    {2, 2}));
        assert(sol.constructRectangle(37) == std::vector<int>(
                                                    {37, 1}));
        assert(sol.constructRectangle(122122) == std::vector<int>(
                                                    {427, 286}));
    }
    return 0;
}