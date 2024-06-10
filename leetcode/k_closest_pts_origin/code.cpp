#include <iostream>
#include <assert.h>

#include <vector>
#include <algorithm>
#include <cmath>

class Solution {
public:
    std::vector<std::vector<int>> kClosest(
                    std::vector<std::vector<int>>& points, 
                    int k) {
        std::ios::sync_with_stdio(0);
        std::sort(points.begin(), points.end(), 
                [](auto &a, auto &b) {
            return std::pow(a[0], 2) + std::pow(a[1], 2) < 
                    std::pow(b[0], 2) + std::pow(b[1], 2);
        });
        return std::vector<std::vector<int>>(
                    points.begin(), points.begin() + k);
    }
};

int main()
{
    Solution sol;
    {
        std::vector<std::vector<int>> points = {{1,3},
                                                {-2,2}};
        int k = 1;
        std::vector<std::vector<int>> res = {{-2, 2}};
        assert(sol.kClosest(points, k) == res);
    }
    return 0;
}